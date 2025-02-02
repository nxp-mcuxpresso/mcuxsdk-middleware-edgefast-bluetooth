/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define IOPCTL_PIO_ANAMUX_DI 0x00u        /*!<@brief Analog mux is disabled */
#define IOPCTL_PIO_FULLDRIVE_DI 0x00u     /*!<@brief Normal drive */
#define IOPCTL_PIO_FUNC0 0x00u            /*!<@brief Selects pin function 0 */
#define IOPCTL_PIO_FUNC1 0x01u            /*!<@brief Selects pin function 1 */
#define IOPCTL_PIO_INBUF_DI 0x00u         /*!<@brief Disable input buffer function */
#define IOPCTL_PIO_INBUF_EN 0x40u         /*!<@brief Enables input buffer function */
#define IOPCTL_PIO_INV_DI 0x00u           /*!<@brief Input function is not inverted */
#define IOPCTL_PIO_PSEDRAIN_DI 0x00u      /*!<@brief Pseudo Output Drain is disabled */
#define IOPCTL_PIO_PULLDOWN_EN 0x00u      /*!<@brief Enable pull-down function */
#define IOPCTL_PIO_PUPD_DI 0x00u          /*!<@brief Disable pull-up / pull-down function */
#define IOPCTL_PIO_PUPD_EN 0x10u          /*!<@brief Enable pull-up / pull-down function */
#define IOPCTL_PIO_SLEW_RATE_NORMAL 0x00u /*!<@brief Normal mode */

/*! @name PIO0_10 (coord J3), SW2
  @{ */
/* Routed pin properties */
#define BOARD_INITPINS_SW2_PERIPHERAL GPIO           /*!<@brief Peripheral name */
#define BOARD_INITPINS_SW2_SIGNAL PIO0               /*!<@brief Signal name */
#define BOARD_INITPINS_SW2_CHANNEL 10                /*!<@brief Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SW2_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_SW2_GPIO_PIN_MASK (1U << 10U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_SW2_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_SW2_PIN 10U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_SW2_PIN_MASK (1U << 10U)      /*!<@brief PORT pin mask */
                                                     /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M33 */

#define IOPCTL_PIO_ANAMUX_DI 0x00u        /*!<@brief Analog mux is disabled */
#define IOPCTL_PIO_FULLDRIVE_DI 0x00u     /*!<@brief Normal drive */
#define IOPCTL_PIO_FUNC1 0x01u            /*!<@brief Selects pin function 1 */
#define IOPCTL_PIO_INBUF_DI 0x00u         /*!<@brief Disable input buffer function */
#define IOPCTL_PIO_INBUF_EN 0x40u         /*!<@brief Enables input buffer function */
#define IOPCTL_PIO_INV_DI 0x00u           /*!<@brief Input function is not inverted */
#define IOPCTL_PIO_PSEDRAIN_DI 0x00u      /*!<@brief Pseudo Output Drain is disabled */
#define IOPCTL_PIO_PULLDOWN_EN 0x00u      /*!<@brief Enable pull-down function */
#define IOPCTL_PIO_PUPD_DI 0x00u          /*!<@brief Disable pull-up / pull-down function */
#define IOPCTL_PIO_SLEW_RATE_NORMAL 0x00u /*!<@brief Normal mode */

/*! @name FC0_RXD_SDA_MOSI_DATA (coord G4), JP40[2]
  @{ */
/* Routed pin properties */
/*!
 * @brief Peripheral name */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RXD_PERIPHERAL FLEXCOMM0
/*!
 * @brief Signal name */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_RXD_SIGNAL RXD_SDA_MOSI_DATA
/* @} */

/*! @name FC0_TXD_SCL_MISO_WS (coord G2), J16[1]/U27[3]/U9[12]
  @{ */
/* Routed pin properties */
/*!
 * @brief Peripheral name */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TXD_PERIPHERAL FLEXCOMM0
/*!
 * @brief Signal name */
#define BOARD_INITDEBUG_UARTPINS_DEBUG_UART_TXD_SIGNAL TXD_SCL_MISO_WS
/* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void); /* Function assigned for the Cortex-M33 */

#define IOPCTL_PIO_ANAMUX_DI 0x00u        /*!<@brief Analog mux is disabled */
#define IOPCTL_PIO_FULLDRIVE_DI 0x00u     /*!<@brief Normal drive */
#define IOPCTL_PIO_FUNC0 0x00u            /*!<@brief Selects pin function 0 */
#define IOPCTL_PIO_INBUF_DI 0x00u         /*!<@brief Disable input buffer function */
#define IOPCTL_PIO_INV_DI 0x00u           /*!<@brief Input function is not inverted */
#define IOPCTL_PIO_PSEDRAIN_DI 0x00u      /*!<@brief Pseudo Output Drain is disabled */
#define IOPCTL_PIO_PULLDOWN_EN 0x00u      /*!<@brief Enable pull-down function */
#define IOPCTL_PIO_PUPD_DI 0x00u          /*!<@brief Disable pull-up / pull-down function */
#define IOPCTL_PIO_SLEW_RATE_NORMAL 0x00u /*!<@brief Normal mode */

/*! @name PIO2_10 (coord T15), U23[3]/SD_RST_N
  @{ */
/* Routed pin properties */
#define BOARD_INITPINSM2_SD_RST_N_PERIPHERAL GPIO                    /*!<@brief Peripheral name */
#define BOARD_INITPINSM2_SD_RST_N_SIGNAL PIO2                        /*!<@brief Signal name */
#define BOARD_INITPINSM2_SD_RST_N_CHANNEL 10                         /*!<@brief Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINSM2_SD_RST_N_GPIO GPIO                          /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINSM2_SD_RST_N_GPIO_PIN_MASK (1U << 10U)          /*!<@brief GPIO pin mask */
#define BOARD_INITPINSM2_SD_RST_N_PORT 2U                            /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINSM2_SD_RST_N_PIN 10U                            /*!<@brief PORT pin number */
#define BOARD_INITPINSM2_SD_RST_N_PIN_MASK (1U << 10U)               /*!<@brief PORT pin mask */
                                                                     /* @} */

/*! @name PIO0_12 (coord E3), Q15[1]/WL_REG_ON
  @{ */
/* Routed pin properties */
#define BOARD_INITPINSM2_WL_REG_ON_PERIPHERAL GPIO                    /*!<@brief Peripheral name */
#define BOARD_INITPINSM2_WL_REG_ON_SIGNAL PIO0                        /*!<@brief Signal name */
#define BOARD_INITPINSM2_WL_REG_ON_CHANNEL 12                         /*!<@brief Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINSM2_WL_REG_ON_GPIO GPIO                          /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINSM2_WL_REG_ON_GPIO_PIN_MASK (1U << 12U)          /*!<@brief GPIO pin mask */
#define BOARD_INITPINSM2_WL_REG_ON_PORT 0U                            /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINSM2_WL_REG_ON_PIN 12U                            /*!<@brief PORT pin number */
#define BOARD_INITPINSM2_WL_REG_ON_PIN_MASK (1U << 12U)               /*!<@brief PORT pin mask */
                                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPinsM2(void); /* Function assigned for the Cortex-M33 */

#define IOPCTL_PIO_ANAMUX_DI 0x00u        /*!<@brief Analog mux is disabled */
#define IOPCTL_PIO_FULLDRIVE_DI 0x00u     /*!<@brief Normal drive */
#define IOPCTL_PIO_FUNC1 0x01u            /*!<@brief Selects pin function 1 */
#define IOPCTL_PIO_INBUF_DI 0x00u         /*!<@brief Disable input buffer function */
#define IOPCTL_PIO_INBUF_EN 0x40u         /*!<@brief Enables input buffer function */
#define IOPCTL_PIO_INV_DI 0x00u           /*!<@brief Input function is not inverted */
#define IOPCTL_PIO_PSEDRAIN_DI 0x00u      /*!<@brief Pseudo Output Drain is disabled */
#define IOPCTL_PIO_PULLDOWN_EN 0x00u      /*!<@brief Enable pull-down function */
#define IOPCTL_PIO_PULLUP_EN 0x20u        /*!<@brief Enable pull-up function */
#define IOPCTL_PIO_PUPD_DI 0x00u          /*!<@brief Disable pull-up / pull-down function */
#define IOPCTL_PIO_PUPD_EN 0x10u          /*!<@brief Enable pull-up / pull-down function */
#define IOPCTL_PIO_SLEW_RATE_NORMAL 0x00u /*!<@brief Normal mode */

/*! @name FC5_RTS_SCL_SSEL1 (coord J15), J28[2]/U32B[3]/J45[36]
  @{ */
/* Routed pin properties */
#define BOARD_INITM2UARTPINS_ACC_RESET_PERIPHERAL FLEXCOMM5           /*!<@brief Peripheral name */
#define BOARD_INITM2UARTPINS_ACC_RESET_SIGNAL RTS_SCL_SSEL1           /*!<@brief Signal name */
                                                                      /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitM2UARTPins(void); /* Function assigned for the Cortex-M33 */

#define IOPCTL_PIO_ANAMUX_DI 0x00u        /*!<@brief Analog mux is disabled */
#define IOPCTL_PIO_FULLDRIVE_DI 0x00u     /*!<@brief Normal drive */
#define IOPCTL_PIO_FUNC0 0x00u            /*!<@brief Selects pin function 0 */
#define IOPCTL_PIO_FUNC1 0x01u            /*!<@brief Selects pin function 1 */
#define IOPCTL_PIO_INBUF_DI 0x00u         /*!<@brief Disable input buffer function */
#define IOPCTL_PIO_INBUF_EN 0x40u         /*!<@brief Enables input buffer function */
#define IOPCTL_PIO_INV_DI 0x00u           /*!<@brief Input function is not inverted */
#define IOPCTL_PIO_PSEDRAIN_DI 0x00u      /*!<@brief Pseudo Output Drain is disabled */
#define IOPCTL_PIO_PSEDRAIN_EN 0x0400u    /*!<@brief Pseudo Output Drain is enabled */
#define IOPCTL_PIO_PULLDOWN_EN 0x00u      /*!<@brief Enable pull-down function */
#define IOPCTL_PIO_PULLUP_EN 0x20u        /*!<@brief Enable pull-up function */
#define IOPCTL_PIO_PUPD_DI 0x00u          /*!<@brief Disable pull-up / pull-down function */
#define IOPCTL_PIO_PUPD_EN 0x10u          /*!<@brief Enable pull-up / pull-down function */
#define IOPCTL_PIO_SLEW_RATE_NORMAL 0x00u /*!<@brief Normal mode */

/*! @name SD0_CARD_DET_N (coord R13), J32[10]/SD_CD
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_CD_PERIPHERAL USDHC0       /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_CD_SIGNAL USDHC_CD_B       /*!<@brief Signal name */
                                                            /* @} */

/*! @name SD0_CLK (coord P10), J32[5]/SD_CLK
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_CLK_PERIPHERAL USDHC0     /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_CLK_SIGNAL USDHC_CLK      /*!<@brief Signal name */
                                                           /* @} */

/*! @name SD0_CMD (coord R9), J32[2]/SD_CMD
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_CMD_PERIPHERAL USDHC0     /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_CMD_SIGNAL USDHC_CMD      /*!<@brief Signal name */
                                                           /* @} */

/*! @name SD0_D0 (coord R11), J32[7]/SD_DAT0
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_DAT0_PERIPHERAL USDHC0      /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_DAT0_SIGNAL USDHC_DATA      /*!<@brief Signal name */
#define BOARD_INITM2_SDHCPINS_SD_DAT0_CHANNEL 0              /*!<@brief Signal channel */
                                                             /* @} */

/*! @name SD0_D1 (coord T11), J32[8]/SD_DAT1
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_DAT1_PERIPHERAL USDHC0      /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_DAT1_SIGNAL USDHC_DATA      /*!<@brief Signal name */
#define BOARD_INITM2_SDHCPINS_SD_DAT1_CHANNEL 1              /*!<@brief Signal channel */
                                                             /* @} */

/*! @name SD0_D2 (coord U11), J32[9]/SD_DAT2
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_DAT2_PERIPHERAL USDHC0      /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_DAT2_SIGNAL USDHC_DATA      /*!<@brief Signal name */
#define BOARD_INITM2_SDHCPINS_SD_DAT2_CHANNEL 2              /*!<@brief Signal channel */
                                                             /* @} */

/*! @name SD0_D3 (coord T12), J32[1]/SD_DAT3
  @{ */
/* Routed pin properties */
#define BOARD_INITM2_SDHCPINS_SD_DAT3_PERIPHERAL USDHC0      /*!<@brief Peripheral name */
#define BOARD_INITM2_SDHCPINS_SD_DAT3_SIGNAL USDHC_DATA      /*!<@brief Signal name */
#define BOARD_INITM2_SDHCPINS_SD_DAT3_CHANNEL 3              /*!<@brief Signal channel */
                                                             /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitM2_SDHCPins(void); /* Function assigned for the Cortex-M33 */

#define IOPCTL_PIO_ANAMUX_DI 0x00u        /*!<@brief Analog mux is disabled */
#define IOPCTL_PIO_FULLDRIVE_DI 0x00u     /*!<@brief Normal drive */
#define IOPCTL_PIO_FULLDRIVE_EN 0x0100u   /*!<@brief Full drive enable */
#define IOPCTL_PIO_FUNC0 0x00u            /*!<@brief Selects pin function 0 */
#define IOPCTL_PIO_FUNC5 0x05u            /*!<@brief Selects pin function 5 */
#define IOPCTL_PIO_FUNC6 0x06u            /*!<@brief Selects pin function 6 */
#define IOPCTL_PIO_INBUF_DI 0x00u         /*!<@brief Disable input buffer function */
#define IOPCTL_PIO_INBUF_EN 0x40u         /*!<@brief Enables input buffer function */
#define IOPCTL_PIO_INV_DI 0x00u           /*!<@brief Input function is not inverted */
#define IOPCTL_PIO_PSEDRAIN_DI 0x00u      /*!<@brief Pseudo Output Drain is disabled */
#define IOPCTL_PIO_PULLDOWN_EN 0x00u      /*!<@brief Enable pull-down function */
#define IOPCTL_PIO_PUPD_DI 0x00u          /*!<@brief Disable pull-up / pull-down function */
#define IOPCTL_PIO_SLEW_RATE_NORMAL 0x00u /*!<@brief Normal mode */

/*! @name FLEXSPI0B_DATA0 (coord L2), JP36[2]
  @{ */
/* Routed pin properties */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA0_PERIPHERAL FLEXSPI       /*!<@brief Peripheral name */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA0_SIGNAL FLEXSPI_B_DATA0   /*!<@brief Signal name */
                                                                      /* @} */

/*! @name FLEXSPI0B_DATA1 (coord M2), JP37[2]
  @{ */
/* Routed pin properties */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA1_PERIPHERAL FLEXSPI       /*!<@brief Peripheral name */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA1_SIGNAL FLEXSPI_B_DATA1   /*!<@brief Signal name */
                                                                      /* @} */

/*! @name FLEXSPI0B_DATA2 (coord N1), JP38[2]
  @{ */
/* Routed pin properties */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA2_PERIPHERAL FLEXSPI       /*!<@brief Peripheral name */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA2_SIGNAL FLEXSPI_B_DATA2   /*!<@brief Signal name */
                                                                      /* @} */

/*! @name FLEXSPI0B_DATA3 (coord N2), JP39[2]
  @{ */
/* Routed pin properties */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA3_PERIPHERAL FLEXSPI       /*!<@brief Peripheral name */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_DATA3_SIGNAL FLEXSPI_B_DATA3   /*!<@brief Signal name */
                                                                      /* @} */

/*! @name FLEXSPI0B_SCLK (coord U3), U19[B2]
  @{ */
/* Routed pin properties */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_SCK_PERIPHERAL FLEXSPI      /*!<@brief Peripheral name */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_SCK_SIGNAL FLEXSPI_B_SCLK   /*!<@brief Signal name */
                                                                   /* @} */

/*! @name FLEXSPI0B_SS0_N (coord T2), JP35[2]
  @{ */
/* Routed pin properties */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_CS0_PERIPHERAL FLEXSPI       /*!<@brief Peripheral name */
#define BOARD_INITFLEXSPI0BPINS_QSPI_B_CS0_SIGNAL FLEXSPI_B_SS0_B   /*!<@brief Signal name */
                                                                    /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitFlexSPI0BPins(void); /* Function assigned for the Cortex-M33 */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
