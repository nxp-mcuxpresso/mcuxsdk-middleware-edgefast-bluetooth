/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*${header:start}*/
#include "clock_config.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_dmamux.h"
#include "fsl_edma.h"
#include "fsl_adapter_audio.h"
#include "fsl_codec_common.h"
#include "fsl_wm8962.h"
#include "fsl_codec_adapter.h"
#include "fsl_debug_console.h"
#include "fsl_adapter_uart.h"
#include "controller_hci_uart.h"
#include "usb_host_config.h"
#include "usb_phy.h"
#include "usb_host.h"

#if (((defined(CONFIG_BT_SMP)) && (CONFIG_BT_SMP)))
#include "ksdk_mbedtls.h"
#endif /* CONFIG_BT_SMP */
#include "fsl_gpt.h"
/*${header:end}*/

/*${macro:start}*/
#if defined(__GIC_PRIO_BITS)
#define USB_HOST_INTERRUPT_PRIORITY (25U)
#elif defined(__NVIC_PRIO_BITS) && (__NVIC_PRIO_BITS >= 3)
#define USB_HOST_INTERRUPT_PRIORITY (6U)
#else
#define USB_HOST_INTERRUPT_PRIORITY (3U)
#endif
/*${macro:end}*/

/*${variable:start}*/
/* Select Audio/Video PLL (393.24 MHz) as sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_SELECT      (2U)
/* Clock pre divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER (3U)
/* Clock divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_DIVIDER     (7U)
/* Get frequency of sai1 clock */
#define DEMO_SAI_CLK_FREQ                                                        \
    (CLOCK_GetFreq(kCLOCK_AudioPllClk) / (DEMO_SAI1_CLOCK_SOURCE_DIVIDER + 1U) / \
     (DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER + 1U))

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_SELECT  (0U)
/* Clock divider for master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_DIVIDER (5U)

#define DEMO_SAI                SAI1
#define DEMO_AUDIO_INSTANCE     (1U)

/* DMA */
#define EXAMPLE_DMAMUX_INSTANCE (0U)
#define EXAMPLE_DMA_INSTANCE    (0U)
#define EXAMPLE_TX_CHANNEL      (0U)
#define EXAMPLE_SAI_TX_SOURCE   (kDmaRequestMuxSai1Tx)

/* GPT - SyncTimer */
#if defined(WIFI_IW612_BOARD_MURATA_2EL_M2)
#define SyncTimer_GPT                (GPT2)
#define SyncTimer_GPT_Irq            (GPT2_IRQn)
#define SyncTimer_GPT_ClockRoot      (kCLOCK_Root_Gpt2)
#define SyncTimer_GPT_ClockRoot_Mux  (kCLOCK_GPT2_ClockRoot_MuxAudioPllOut)
#define SyncTimer_GPT_ClockRoot_Div  (16)
#endif
#if defined(WIFI_IW612_BOARD_MURATA_2EL_M2)
static volatile uint32_t SyncTimer_Trigger_Counter; /* This used to counter the sync trigger signal. */
static void (*SyncTimer_Trigger_Callback)(uint32_t sync_index, uint64_t bclk_count) = NULL;
static volatile uint32_t SyncTimer_Capture1_Value = 0;
static volatile uint32_t SyncTimer_Pre_Capture2_Value = 0;
static volatile uint64_t SyncTimer_Count_Value = 0;
static volatile uint32_t SyncTimer_Count_To_Bclk_Div = 0;
static volatile uint64_t SyncTimer_Bclk_Value = 0;
#endif

/* demo audio data channel */
#define DEMO_AUDIO_DATA_CHANNEL (kHAL_AudioStereo)
/* demo audio bit width */
#define DEMO_AUDIO_BIT_WIDTH (kHAL_AudioWordWidth16bits)
/* demo audio sample frequency */
#define DEMO_AUDIO_SAMPLING_RATE (kHAL_AudioSampleRate16KHz)

wm8962_config_t wm8962Config = {
    .i2cConfig = {.codecI2CInstance = BOARD_CODEC_I2C_INSTANCE, .codecI2CSourceClock = BOARD_CODEC_I2C_CLOCK_FREQ},
    .route =
        {
            .enableLoopBack            = false,
            .leftInputPGASource        = kWM8962_InputPGASourceInput1,
            .leftInputMixerSource      = kWM8962_InputMixerSourceInputPGA,
            .rightInputPGASource       = kWM8962_InputPGASourceInput3,
            .rightInputMixerSource     = kWM8962_InputMixerSourceInputPGA,
            .leftHeadphoneMixerSource  = kWM8962_OutputMixerDisabled,
            .leftHeadphonePGASource    = kWM8962_OutputPGASourceDAC,
            .rightHeadphoneMixerSource = kWM8962_OutputMixerDisabled,
            .rightHeadphonePGASource   = kWM8962_OutputPGASourceDAC,
        },
    .slaveAddress = WM8962_I2C_ADDR,
    .bus          = kWM8962_BusI2S,
    .format       = {.mclk_HZ    = 12288000U,
               .sampleRate = kWM8962_AudioSampleRate16KHz,
               .bitWidth   = kWM8962_AudioBitWidth16bit},
    .masterSlave  = false,
};
codec_config_t boardCodecConfig = {.codecDevType = kCODEC_WM8962, .codecDevConfig = &wm8962Config};

/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM) / (POST)
 *                              = 24 * (30 + 106/1000) / 1
 *                              = 722.544MHz
 */
/*setting for 44.1Khz*/
const clock_audio_pll_config_t audioCodecPllConfig = {
    .loopDivider = 30,   /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 1,    /* Divider after the PLL, should only be 1, 2, 4, 8, 16. */
    .numerator   = 106,  /* 30 bit numerator of fractional loop divider. */
    .denominator = 1000, /* 30 bit denominator of fractional loop divider */
};

/*
 * AUDIO PLL setting: Frequency = Fref * (DIV_SELECT + NUM / DENOM) / (2^POST)
 *                              = 24 * (32 + 7680/10000) / 2
 *                              = 393.216 MHZ
 */
/*setting for multiple of 8Khz,such as 48Khz/16Khz/32KHz*/
const clock_audio_pll_config_t audioCodecPllConfig1 = {
    .loopDivider = 32,  /* PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 2,   /* Divider after the PLL, should only be 1, 2, 4, 8, 16. */
    .numerator   = 7680,  /* 30 bit numerator of fractional loop divider. */
    .denominator = 10000, /* 30 bit denominator of fractional loop divider */
};

hal_audio_dma_mux_config_t audioTxDmaMuxConfig = {
    .dmaMuxConfig.dmaMuxInstance   = EXAMPLE_DMAMUX_INSTANCE,
    .dmaMuxConfig.dmaRequestSource = EXAMPLE_SAI_TX_SOURCE,
};

hal_audio_dma_config_t audioTxDmaConfig = {
    .instance             = EXAMPLE_DMA_INSTANCE,
    .channel              = EXAMPLE_TX_CHANNEL,
    .enablePreemption     = false,
    .enablePreemptAbility = false,
    .priority             = kHAL_AudioDmaChannelPriorityDefault,
    .dmaMuxConfig         = (void *)&audioTxDmaMuxConfig,
    .dmaChannelMuxConfig  = NULL,
};

hal_audio_ip_config_t audioTxIpConfig = {
    .sai.lineMask = 1U << 0U,
    .sai.syncMode = kHAL_AudioSaiModeAsync,
};

hal_audio_config_t audioTxConfig = {
    .dmaConfig         = &audioTxDmaConfig,
    .ipConfig          = (void *)&audioTxIpConfig,
    .srcClock_Hz       = 12288000U,
    .sampleRate_Hz     = (uint32_t)DEMO_AUDIO_SAMPLING_RATE,
//    .fifoWatermark     = FSL_FEATURE_SAI_FIFO_COUNTn(DEMO_SAI) / 2U,
    /* Here we use this config to use 4bytes align, otherwise will trigger 32bytes align assert. */
    .fifoWatermark     = FSL_FEATURE_SAI_FIFO_COUNTn(DEMO_SAI) - 2,
    .masterSlave       = kHAL_AudioMaster,
    .bclkPolarity      = kHAL_AudioSampleOnRisingEdge,
    .frameSyncWidth    = kHAL_AudioFrameSyncWidthHalfFrame,
    .frameSyncPolarity = kHAL_AudioBeginAtFallingEdge,
    .lineChannels      = DEMO_AUDIO_DATA_CHANNEL,
    .dataFormat        = kHAL_AudioDataFormatI2sClassic,
    .bitWidth          = (uint8_t)DEMO_AUDIO_BIT_WIDTH,
    .instance          = DEMO_AUDIO_INSTANCE,
};

/*${variable:end}*/

/*${function:start}*/
void BOARD_EnableSaiMclkOutput(bool enable)
{
    if (enable)
    {
        IOMUXC_GPR->GPR1 |= IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK;
    }
    else
    {
        IOMUXC_GPR->GPR1 &= (~IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK);
    }
}

uint32_t BOARD_SwitchAudioFreq(uint32_t sampleRate)
{
    CLOCK_DeinitAudioPll();

    if (0U == sampleRate)
    {
        /* Disable MCLK output */
        BOARD_EnableSaiMclkOutput(false);
    }
    else
    {
        if (44100U == sampleRate)
        {
            CLOCK_InitAudioPll(&audioCodecPllConfig);
        }
        else if (0U == sampleRate % 8000U)
        {
            CLOCK_InitAudioPll(&audioCodecPllConfig1);
        }
        else
        {
            /* no action */
        }

        /*Clock setting for LPI2C*/
        CLOCK_SetMux(kCLOCK_Lpi2cMux, DEMO_LPI2C_CLOCK_SOURCE_SELECT);
        CLOCK_SetDiv(kCLOCK_Lpi2cDiv, DEMO_LPI2C_CLOCK_SOURCE_DIVIDER);

        /*Clock setting for SAI1*/
        CLOCK_SetMux(kCLOCK_Sai1Mux, DEMO_SAI1_CLOCK_SOURCE_SELECT);
        CLOCK_SetDiv(kCLOCK_Sai1PreDiv, DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER);
        CLOCK_SetDiv(kCLOCK_Sai1Div, DEMO_SAI1_CLOCK_SOURCE_DIVIDER);
        
        /* Enable MCLK output */
        BOARD_EnableSaiMclkOutput(true);
    }
    
    wm8962Config.format.sampleRate             = sampleRate;
    wm8962Config.format.mclk_HZ                = DEMO_SAI_CLK_FREQ;

    return DEMO_SAI_CLK_FREQ;
}

#if defined(WIFI_IW612_BOARD_MURATA_2EL_M2)
void BOARD_SyncTimer_Init(void (*sync_timer_callback)(uint32_t sync_index, uint64_t bclk_count))
{
    gpt_config_t config;

    /* 2EL use GPT2 as SyncTimer. */
    BOARD_InitGPT2Pins();

    GPT_GetDefaultConfig(&config);
    config.clockSource = kGPT_ClockSource_Ext; /* GPT2_CLK come from EXT_CLOCK. */
    config.divider = 1U;
    config.enableRunInStop = true;
    config.enableRunInWait = true;
    config.enableRunInDoze = false;
    config.enableRunInDbg = false;
    config.enableFreeRun = true;
    config.enableMode  = true;
    GPT_Init(SyncTimer_GPT, &config);

    /* Input Capture 1 capture signal come from SAI FS signal, in order to capture offset between BCLK and FS. */
    GPT_SetInputOperationMode(SyncTimer_GPT, kGPT_InputCapture_Channel1, kGPT_InputOperation_RiseEdge);
    //GPT_EnableInterrupts(SyncTimer_GPT, kGPT_InputCapture1InterruptEnable);
    /* Input Capture 2 capture signal come from Sync INT signal, on order to measure CLK draft. */
    GPT_SetInputOperationMode(SyncTimer_GPT, kGPT_InputCapture_Channel2, kGPT_InputOperation_RiseEdge);
    //GPT_EnableInterrupts(SyncTimer_GPT, kGPT_InputCapture2InterruptEnable);

    EnableIRQWithPriority(SyncTimer_GPT_Irq, 3);

    SyncTimer_Trigger_Callback = sync_timer_callback;
}

void BORAD_SyncTimer_Start(uint32_t sample_rate, uint32_t bits_per_sample, uint32_t sync_index_init)
{
    /* Reset all parameter values. */
    SyncTimer_Trigger_Counter    = sync_index_init;
    SyncTimer_Capture1_Value     = 0;
    SyncTimer_Pre_Capture2_Value = 0;
    SyncTimer_Count_Value        = 0;
    SyncTimer_Count_To_Bclk_Div  = DEMO_SAI_CLK_FREQ / (sample_rate * bits_per_sample);
    SyncTimer_Bclk_Value         = 0;

    GPT_ClearStatusFlags(SyncTimer_GPT, kGPT_InputCapture1Flag);
    GPT_ClearStatusFlags(SyncTimer_GPT, kGPT_InputCapture2Flag);
    GPT_EnableInterrupts(SyncTimer_GPT, kGPT_InputCapture1InterruptEnable);
    GPT_EnableInterrupts(SyncTimer_GPT, kGPT_InputCapture2InterruptEnable);
    GPT_StartTimer(SyncTimer_GPT);
}

void BORAD_SyncTimer_Stop(void)
{
    GPT_StopTimer(SyncTimer_GPT);
}

void GPT2_IRQHandler(void)
{
    uint32_t flag;
    uint32_t current_capture2_value;
    uint32_t capture2_value_delta;

    flag  = GPT_GetStatusFlags(SyncTimer_GPT, (gpt_status_flag_t)(kGPT_InputCapture1Flag | kGPT_InputCapture2Flag));
    flag &= GPT_GetEnabledInterrupts(SyncTimer_GPT);

    if(flag & kGPT_InputCapture1Flag)
    {
        /* We only need capture the first SAI FS signal to calculate offset. */
        GPT_DisableInterrupts(SyncTimer_GPT, kGPT_InputCapture1InterruptEnable);
        GPT_ClearStatusFlags(SyncTimer_GPT, kGPT_InputCapture1Flag);
        /* SAI FS trigged BCLK offset. */
        SyncTimer_Capture1_Value = GPT_GetInputCaptureValue(SyncTimer_GPT, kGPT_InputCapture_Channel1);
    }
    if(flag & kGPT_InputCapture2Flag)
    {
        GPT_ClearStatusFlags(SyncTimer_GPT, kGPT_InputCapture2Flag);
        /* Sync INT trigged BCLK count capture. */
        current_capture2_value = GPT_GetInputCaptureValue(SyncTimer_GPT, kGPT_InputCapture_Channel2);
        /* Fix GPT overflow issue. */
        if (current_capture2_value < SyncTimer_Pre_Capture2_Value)
        {
            capture2_value_delta = (uint64_t)0x100000000 + current_capture2_value - SyncTimer_Pre_Capture2_Value;
        }
        else
        {
            capture2_value_delta = current_capture2_value - SyncTimer_Pre_Capture2_Value;
        }
        SyncTimer_Pre_Capture2_Value = current_capture2_value;
        SyncTimer_Count_Value += capture2_value_delta;

        /* Calculate BCLK. */
        /* BCLK should be 0 before the SAI_SW start, because we use AUDIO_PLL as clk source. */
        if(SyncTimer_Capture1_Value > 0U)
        {
            SyncTimer_Bclk_Value = (SyncTimer_Count_Value - SyncTimer_Capture1_Value) / SyncTimer_Count_To_Bclk_Div;
        }
        else
        {
            SyncTimer_Bclk_Value = 0;
        }
        /* invoke callback. */
        if(SyncTimer_Trigger_Callback)
        {
            SyncTimer_Trigger_Callback(SyncTimer_Trigger_Counter, SyncTimer_Bclk_Value);
        }

        /* SyncTimer trigger signal count. */
        SyncTimer_Trigger_Counter ++;
    }

    SDK_ISR_EXIT_BARRIER;
}
#endif /* WIFI_IW612_BOARD_MURATA_2EL_M2 */

void BOARD_InitHardware(void)
{
#if (defined(HAL_UART_DMA_ENABLE) && (HAL_UART_DMA_ENABLE > 0U))
    DMAMUX_Type *dmaMuxBases[] = DMAMUX_BASE_PTRS;
    edma_config_t config;
    DMA_Type *dmaBases[] = DMA_BASE_PTRS;
#endif

    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

#if (defined(HAL_UART_DMA_ENABLE) && (HAL_UART_DMA_ENABLE > 0U))
    DMAMUX_Init(dmaMuxBases[EXAMPLE_DMAMUX_INSTANCE]);
    EDMA_GetDefaultConfig(&config);
    EDMA_Init(dmaBases[EXAMPLE_DMA_INSTANCE], &config);
#endif
#if (((defined(CONFIG_BT_SMP)) && (CONFIG_BT_SMP)))
    CRYPTO_InitHardware();
#endif /* CONFIG_BT_SMP */
}

#if defined(WIFI_IW612_BOARD_MURATA_2EL_M2)
int controller_hci_uart_get_configuration(controller_hci_uart_config_t *config)
{
    if (NULL == config)
    {
        return -1;
    }
    config->clockSrc        = BOARD_BT_UART_CLK_FREQ;
    config->defaultBaudrate = 115200u;
    config->runningBaudrate = BOARD_BT_UART_BAUDRATE;
    config->instance        = BOARD_BT_UART_INSTANCE;
#if (defined(HAL_UART_DMA_ENABLE) && (HAL_UART_DMA_ENABLE > 0U))
    config->dma_instance     = 0U;
    config->rx_channel       = 1U;
    config->tx_channel       = 2U;
    config->dma_mux_instance = 0U;
    config->rx_request       = kDmaRequestMuxLPUART3Rx;
    config->tx_request       = kDmaRequestMuxLPUART3Tx;
#endif
    config->enableRxRTS = 1u;
    config->enableTxCTS = 1u;
    return 0;
}
#endif

void USB_HostClockInit(void)
{
    usb_phy_config_struct_t phyConfig = {
        BOARD_USB_PHY_D_CAL,
        BOARD_USB_PHY_TXCAL45DP,
        BOARD_USB_PHY_TXCAL45DM,
    };

    if (CONTROLLER_ID == kUSB_ControllerEhci0)
    {
        CLOCK_EnableUsbhs0PhyPllClock(kCLOCK_Usbphy480M, 480000000U);
        CLOCK_EnableUsbhs0Clock(kCLOCK_Usb480M, 480000000U);
    }
    else
    {
        CLOCK_EnableUsbhs1PhyPllClock(kCLOCK_Usbphy480M, 480000000U);
        CLOCK_EnableUsbhs1Clock(kCLOCK_Usb480M, 480000000U);
    }
    USB_EhciPhyInit(CONTROLLER_ID, BOARD_XTAL0_CLK_HZ, &phyConfig);
}

void USB_HostIsrEnable(void)
{
    uint8_t irqNumber;

    uint8_t usbHOSTEhciIrq[] = USBHS_IRQS;
    irqNumber                = usbHOSTEhciIrq[CONTROLLER_ID - kUSB_ControllerEhci0];

/* Install isr, set priority, and enable IRQ. */
#if defined(__GIC_PRIO_BITS)
    GIC_SetPriority((IRQn_Type)irqNumber, USB_HOST_INTERRUPT_PRIORITY);
#else
    NVIC_SetPriority((IRQn_Type)irqNumber, USB_HOST_INTERRUPT_PRIORITY);
#endif
    EnableIRQ((IRQn_Type)irqNumber);
}
/*${function:end}*/
