mcux_set_variable(wireless_ble_core_arch ${CONFIG_MCUX_HW_CORE})
mcux_set_variable(wireless_ble_lib_sel_dsp ${CONFIG_MCUX_HW_DSP})
# message("CONFIG_MCUX_HW_CORE=${CONFIG_MCUX_HW_CORE}.")
# message("CONFIG_MCUX_HW_DSP=${CONFIG_MCUX_HW_DSP}.")
if (NOT((CONFIG_MCUX_HW_CORE STREQUAL "cm33") AND (CONFIG_MCUX_HW_DSP STREQUAL "NO_DSP")))
    mcux_set_variable(wireless_ble_lib_sel ${CONFIG_MCUX_HW_CORE})
endif()
if ((CONFIG_MCUX_HW_CORE STREQUAL "cm33") AND (CONFIG_MCUX_HW_DSP STREQUAL "NO_DSP"))
    mcux_set_variable(wireless_ble_lib_sel cm33nodsp)
endif()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.pal)
    # mcux_add_include(
    #     INCLUDES boards/${board}/edgefast_bluetooth_examples/configs
    # )
    mcux_add_source(
        SOURCES boards/template/dummy.txt
    )
    # mcux_add_source(
    #     SOURCES boards/${board}/edgefast_bluetooth_examples/configs/FreeRTOSConfig.h
    # )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.common.ethermind.hci)
    mcux_add_source(
        SOURCES boards/template/dummy.txt
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.common.ethermind.hci_uart)
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/hci_uart.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/hci_uart.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/hci_uart_internal.h
    )
    mcux_add_configuration(
        CC "-DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING=1 -DSERIAL_PORT_TYPE_UART=1"
        CX "-DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING=1 -DSERIAL_PORT_TYPE_UART=1"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.common.ethermind.hci_platform)
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/hci_platform.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/hci_platform.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.common.ethermind)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/export/eOSAL
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/export/include
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/export/vendor
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/att
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/avctp
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/avdtp
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/bnep
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/dbase
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/hci_1.2
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/mcap
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/obex
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/rfcomm
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/sdp
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/sm
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/protocols/smp
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/aes_cmac
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/at_parser
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/object_parser
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/racp
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/storage
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/xml_parser
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/bluetooth
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/ethal
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/toolspec/mcuxpresso
        TOOLCHAINS mcux
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/sbc
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/osal/src/freertos
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/sbc
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_assert.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_config.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_debug_api.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_fops.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_os.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_serial.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/eOSAL/eBT_timer.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/include/*.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/vendor/vendor_specific_commands.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/vendor/vendor_specific_init.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/vendor/vendor_specific_init.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/att/att.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/avctp/avctp.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/avdtp/avdtp.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/bnep/bnep.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/dbase/database.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/hci_1.2/hci_h.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/mcap/mcap.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/obex/obex.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/rfcomm/rfcomm.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/sdp/sdp.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/sm/sm.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/sm/sm_extern.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/sm/sm_internal.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/smp/smp.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/smp/smp_extern.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/smp/smp_fsm.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/smp/smp_fsm_engine.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/protocols/smp/smp_internal.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/aes_cmac/*.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/at_parser/at_parser_hsp_hfp.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/object_parser/*.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/racp/*.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/storage/storage.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/xml_parser/xml_common_defines.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/xml_parser/xml_encoder.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/xml_parser/xml_parser.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/osal/src/freertos/*.*
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_assert.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_config.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_debug.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_debug_api.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_fops.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_os.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_status_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_storage_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_storage_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/BT_timer.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/btsnoop_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/btsnoop_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/sco_audio_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/sco_audio_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/ctn_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/ctn_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/ftp_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/ftp_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/hci_uart_internal.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/ht_read_task_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/map_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/map_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/obex_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/obex_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/pbap_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/pbap_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/write_task_extern_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/write_task_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/write_task_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/littlefs_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/littlefs_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/fw_loader_uart.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/fw_loader_uart.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/ethal/*.*
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/sbc/sbc_os.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/toolspec/mcuxpresso/*.*
        TOOLCHAINS mcux
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/EM_platform.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/EM_platform.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/sbc/*.h
    )
    mcux_add_configuration(
        CC "-DLFS_NO_INTRINSICS=1 -DLFS_NO_ERROR=1"
        CX "-DLFS_NO_INTRINSICS=1 -DLFS_NO_ERROR=1"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.common.ethermind.lc3)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/lc3
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/lc3/export/include
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/lc3/private/fixed/config
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/lc3/LC3_os.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3/export/include/LC3_api.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3/private/fixed/config/LC3_limits.h
    )
    mcux_add_configuration(
        CC "-DLC3_DSP=1"
        CX "-DLC3_DSP=1"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.common.ethermind.lc3_nodsp)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/lc3_nodsp
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/export/include
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/private/fixed/common
    )
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/private/fixed/config
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/lc3_nodsp/LC3_os.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/export/include/LC3_ndsp_api.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/private/fixed/common/lc3_ndsp_defines.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/private/fixed/common/lc3_ndsp_internal.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/private/fixed/config/LC3_ndsp_features.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/utils/lc3_nodsp/private/fixed/config/LC3_ndsp_limits.h
    )
    mcux_add_configuration(
        CC "-DLC3_DSP=0"
        CX "-DLC3_DSP=0"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.wifi_nxp.controller.base)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/bluetooth/controller
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller_wifi_nxp.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller_hci_uart.h
    )
    mcux_add_macro(
        CC "-DSDIO_ENABLED=1"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.k32w061.controller)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/bluetooth/controller
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/DK6-RN-0065-Production-Flash-Programmer.pdf
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/hci_black_box_bm.bin
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/JN-SW-4407+DK6+Production+Flash+Programmer+v2282.exe
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/ot-rcp.bin
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/ot_rcp_ble_hci_bb_bm_2_uart.bin
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/ot_rcp_ble_hci_bb_bm_single_uart.bin
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/k32w061/readme.txt
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller_k32w.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller_hci_uart.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.rw610.controller)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/port/pal/mcux/bluetooth/controller
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/port/pal/mcux/bluetooth/controller/controller_rw610.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.config.ethermind)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/private/lib/mcux/default/config
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/lib/mcux/default/config/BT_features.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/lib/mcux/default/config/BT_limits.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/private/lib/mcux/default/config/db_gen.h
    )
    mcux_add_source(
        SOURCES boards/template/dummy.txt
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.extension.common.ethermind)
    mcux_add_include(
        INCLUDES ../wireless/ethermind/bluetooth/export/extension
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/aes_cmac_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/aes_cmac_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/BT_common_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/BT_common_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/device_queue_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/device_queue_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/sm_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/sm_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/sm_ssp_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/sm_ssp_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/smp_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/smp_pl.h
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/gatt_db_pl.c
    )
    mcux_add_source(
        SOURCES ../wireless/ethermind/bluetooth/export/extension/gatt_db_pl.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.btble.ethermind)
    mcux_add_include(
        INCLUDES source/impl/ethermind/host
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_a2dp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_a2dp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/a2dp_codec/sbc/a2dp_codec_sbc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_api.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_internal.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_api.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_att.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_eatt.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_at.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_att_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avdtp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_conn.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_data.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ead.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_conn_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_crypto.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_aes_ccm.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_crypto_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_gatt.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_gatt_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_core.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_core.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_adv.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_adv.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_br.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_id.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_id.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_long_wq.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_long_wq.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_iso.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_iso_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_scan.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_scan.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ecc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ecc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_addr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_addr_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_buf.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_buf_view.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_direction.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_direction_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_ecc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br_interface.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_map_mce.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_map_mse.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_map_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_monitor.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_monitor.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rfcomm.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rfcomm_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_spp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rpa.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rpa.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_settings.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_settings.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sdp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sdp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ssp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ssp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_uuid.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hfp_ag.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hfp_hf.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hfp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_pbap_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_pbap_pce.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_pbap_pse.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sco.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sco_internal.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/pbap_pce.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/pbap_pse.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/pbap_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/a2dp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/avrcp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/a2dp_codec_sbc.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/addr.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/common/addr.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/att.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/avdtp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/bluetooth.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/direction.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/buf.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/l2cap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/map_mce.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/map_mse.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/map_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/obex.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/rfcomm.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/spp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/sdp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/conn.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/crypto.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/gap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/gatt.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/byteorder.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/ead.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_raw.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_vs.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hfp_hf.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hfp_ag.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/iso.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/testing.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/uuid.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.ble.ethermind)
    mcux_add_include(
        INCLUDES source/impl/ethermind/host
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_att.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_eatt.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_att_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_conn.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_conn_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_data.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ead.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_crypto.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_aes_ccm.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_crypto_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_gatt.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_gatt_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_core.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_core.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_adv.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_adv.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_br.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_id.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_id.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_long_wq.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_long_wq.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_iso.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_iso_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_scan.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_scan.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ecc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ecc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_addr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_addr_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_buf.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_buf_view.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_direction.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_direction_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_ecc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br_interface.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_monitor.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_monitor.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rpa.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rpa.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_settings.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_settings.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp_null.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ssp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_uuid.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/addr.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/common/addr.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/att.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/bluetooth.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/direction.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/buf.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/l2cap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/conn.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/crypto.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/gap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/gatt.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/ead.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/byteorder.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_raw.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_vs.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/iso.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/testing.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/uuid.h
    )
    mcux_add_configuration(
        CC "-DCFG_BLE"
        CX "-DCFG_BLE"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.br.ethermind)
    mcux_add_macro(
      CC "-DCFG_CLASSIC"
      CX "-DCFG_CLASSIC"
    )
    mcux_add_include(
        INCLUDES source/impl/ethermind/host
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_a2dp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_a2dp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/a2dp_codec/sbc/a2dp_codec_sbc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_api.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_internal.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_al_api.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avrcp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_at.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_att_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_avdtp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_conn.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_conn_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_data.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ead.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_crypto.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_aes_ccm.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_crypto_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_gatt_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_core.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_core.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_adv.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_adv.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_br.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_id.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_id.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_long_wq.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_long_wq.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_scan.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_scan.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ecc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ecc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_addr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_addr_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_buf.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_buf_view.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_direction.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_direction_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hci_ecc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_keys_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_l2cap_br_interface.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_map_mce.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_map_mse.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_map_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_monitor.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_monitor.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rfcomm.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rfcomm_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_spp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rpa.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_rpa.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_settings.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_settings.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sdp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sdp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_smp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ssp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_ssp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_uuid.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hfp_ag.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hfp_hf.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_hfp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_pbap_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_pbap_pce.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_pbap_pse.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sco.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/host/bt_pal_sco_internal.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/pbap_pce.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/pbap_pse.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/pbap_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/a2dp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/avrcp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/a2dp_codec_sbc.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/addr.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/common/addr.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/att.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/avdtp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/bluetooth.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/direction.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/buf.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/l2cap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/map_mce.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/map_mse.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/map_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/obex.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/rfcomm.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/spp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/sdp.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/conn.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/crypto.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/gap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/gatt.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/byteorder.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_types.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/ead.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_raw.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hci_vs.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hfp_hf.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/hfp_ag.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/iso.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/testing.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/uuid.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.wifi_nxp.controller.lwip.config)
    mcux_add_include(
        INCLUDES source/impl/ethermind/controller/configs/lwip
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/controller/configs/lwip/lwipopts.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/controller/configs/lwip/lwippools.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.wifi_nxp.controller.wifi.config)
    mcux_add_include(
        INCLUDES source/impl/ethermind/controller/configs/wifi
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/controller/configs/wifi/wifi_config.h
    )
endif ()

# test
if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.config.template)
    # mcux_add_source(
    #     SOURCES edgefast_bluetooth_config_include.h
    # )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.cap)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_cap.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/cap.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/cap_acceptor.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/cap_commander.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/cap_common.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/cap_initiator.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/cap_stream.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/cap_internal.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.aics)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_aics.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/aics.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/aics.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/aics_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/aics_internal.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.vocs)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_vocs.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/vocs.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/vocs.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/vocs_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/vocs_internal.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.vcp)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_vcp.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/vcp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/vcp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/vcp_vol_ctlr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/vcp_vol_rend.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.micp)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_micp.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/micp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/micp_mic_ctlr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/micp_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/micp_mic_dev.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.csip)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_csip.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/csip.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/csip_crypto.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/csip_crypto.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/csip_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/csip_set_coordinator.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/csip_set_member.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.ccid)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/ccid_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/ccid.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.mcs)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_mcs.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/mcs.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/mcs.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/mcs_internal.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.mcc)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_mcs.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/mcc.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/mcc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/mcc_internal.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.mpl)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_mpl.h
    # )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_mctl.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/media_proxy.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/media_proxy.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/media_proxy_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/mpl.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/mpl_internal.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.bap)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    mcux_add_include(
        INCLUDES source/impl/ethermind
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_ascs.h
    # )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_bap.h
    # )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_pacs.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/audio.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/audio/bap_lc3_preset.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/audio/bap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/audio/lc3.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/audio/pacs.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/ascs_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/ascs.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/audio_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_iso.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_iso.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/audio.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_base.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_broadcast_sink.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_broadcast_source.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/codec.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_endpoint.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/pacs_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/pacs.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_stream.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_stream.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_unicast_client_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_unicast_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_unicast_server.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_unicast_server.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.bass)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_bass.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/bap.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_broadcast_assistant.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/bap_scan_delegator.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.has)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_has.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/has.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/has_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/has_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/has.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.tbs)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_tbs.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/tbs.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/tbs_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/tbs_internal.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/tbs.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.tmap)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_tmap.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/tmap.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/tmap.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.gmap)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_gmap.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/gmap.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/audio/gmap_lc3_preset.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/gmap_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/gmap_server.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.le_audio.pbp)
    mcux_add_include(
        INCLUDES include/bluetooth/audio
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/audio/config
    # )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/audio/config/config_pbp.h
    # )
    mcux_add_source(
        SOURCES include/bluetooth/audio/pbp.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/pbp.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.hrs)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/hrs.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/hrs.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.bas)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/bas.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/bas.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.dis)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/dis.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/dis.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.hts)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/hts.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/hts.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.ias)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/ias/ias.c
    )
    mcux_add_source(
        SOURCES source/services/ias/ias_client.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/ias.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.hps)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/hps.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/hps.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.pxr)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/pxr.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/pxr.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.ipsp)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/ipsp.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/ipsp.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.ots)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES source/services/ots
    )
    mcux_add_include(
        INCLUDES include/bluetooth/services
    )
    # mcux_add_include(
    #     INCLUDES include/bluetooth/services/config
    # )
    mcux_add_source(
        SOURCES source/services/ots/ots.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_client.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_client_internal.h
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_dir_list.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_dir_list_internal.h
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_internal.h
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_l2cap.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_l2cap_internal.h
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_oacp.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_oacp_internal.h
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_obj_manager.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_obj_manager_internal.h
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_olcp.c
    )
    mcux_add_source(
        SOURCES source/services/ots/ots_olcp_internal.h
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/ots.h
    )
    # mcux_add_source(
    #     SOURCES include/bluetooth/services/config/config_ots.h
    # )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.wu)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/wu.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/wu.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.fmp)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/fmp.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/fmp.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.profile.tip)
    mcux_add_include(
        INCLUDES source/services
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/services/tip.c
    )
    mcux_add_source(
        SOURCES include/bluetooth/services/tip.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.pal.crypto.ethermind)
    mcux_add_include(
        INCLUDES source/impl/ethermind/crypto
    )
    mcux_add_include(
        INCLUDES source/impl/ethermind/host
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/crypto/bt_crypto.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/crypto/bt_crypto.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.pal.platform.ethermind)
    mcux_add_include(
        INCLUDES source/impl/ethermind/platform
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/bt_ble_platform.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/bt_ble_platform.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/bt_ble_settings.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/bt_ble_settings.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.pal.host_msd_fatfs.ethermind)
    mcux_add_include(
        INCLUDES source/impl/ethermind/platform
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/host_msd_fatfs.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/host_msd_fatfs.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.pal.host_msd_fatfs.ethermind.config)
    mcux_add_include(
        INCLUDES source/impl/ethermind/platform/configs
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/platform/configs/ffconf.h
    )
    # the config are converted into Kconfig symbol in middleware/usb
    # mcux_add_source(
    #     SOURCES source/impl/ethermind/platform/configs/usb_host_config.h
    # )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.pal.db_gen.ethermind)
    mcux_add_include(
        INCLUDES source/impl/ethermind/
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/bt_db_gen.c
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.porting.atomic)
    mcux_add_include(
        INCLUDES source/porting
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/porting/atomic_c.c
    )
    mcux_add_source(
        SOURCES include/sys/atomic.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.porting.list)
    mcux_add_include(
        INCLUDES source/porting
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES include/sys/slist.h
    )
    mcux_add_source(
        SOURCES include/sys/dlist.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.porting.net)
    mcux_add_include(
        INCLUDES source/porting
    )
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES source/porting/net/buf.c
    )
    mcux_add_source(
        SOURCES source/porting/net/buf_simple.c
    )
    mcux_add_source(
        SOURCES include/net/buf.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.porting.toolchain)
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_source(
        SOURCES include/toolchain/common.h
    )
    mcux_add_source(
        SOURCES include/toolchain/gcc.h
    )
    mcux_add_source(
        SOURCES include/toolchain/iar.h
    )
    mcux_add_source(
        SOURCES include/toolchain/armcc.h
    )
    mcux_add_source(
        SOURCES include/toolchain.h
    )
    mcux_add_source(
        SOURCES boards/template/dummy.txt
    )
    mcux_add_configuration(
        CC "-DCONFIG_ARM=1"
        CX "-DCONFIG_ARM=1"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.porting.work_queue)
    mcux_add_include(
        INCLUDES source/porting
    )
    mcux_add_source(
        SOURCES source/porting/work/work.c
    )
    mcux_add_source(
        SOURCES source/porting/work/work.h
    )
endif ()

# if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.config.template)
#     mcux_add_include(
#         INCLUDES include
#         TARGET_FILES edgefast_bluetooth_config.h
#     )
#     mcux_add_include(
#         INCLUDES examples/template/app_bluetooth_config
#         TARGET_FILES app_bluetooth_config.h
#     )
#     mcux_add_source(
#         SOURCES include/edgefast_bluetooth_config.h
#     )
#     mcux_add_source(
#         SOURCES include/edgefast_bluetooth_debug_config.h
#     )
#     mcux_add_source(
#         SOURCES examples/template/app_bluetooth_config/app_bluetooth_config.h
#     )
# endif ()

# if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.mcux.linker.template)
#     mcux_add_source(
#         SOURCES boards/template/dummy.txt
#     )
#     mcux_add_source(
#         SOURCES ${board}/edgefast_bluetooth_examples/template/linker/mcux/end_text.ldt
#         TOOLCHAINS mcux
#     )
#     mcux_add_source(
#         SOURCES ${board}/edgefast_bluetooth_examples/template/linker/mcux/main_data.ldt
#         TOOLCHAINS mcux
#     )
#     mcux_add_source(
#         SOURCES ${board}/edgefast_bluetooth_examples/template/linker/mcux/main_text.ldt
#         TOOLCHAINS mcux
#     )
#     mcux_add_source(
#         SOURCES ${board}/edgefast_bluetooth_examples/template/linker/mcux/symbols.ldt
#         TOOLCHAINS mcux
#     )
#     mcux_add_source(
#         SOURCES ${board}/edgefast_bluetooth_examples/template/linker/mcux/data.ldt
#         TOOLCHAINS mcux
#         DEVICES MIMXRT1052 MIMXRT1062 MIMXRT1042 MIMXRT1189 MIMXRT1187 MCXN547
#     )
# endif ()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.sdio.template)
    # mcux_add_source(
    #     SOURCES boards/template/dummy.txt
    # )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.template)
    mcux_add_include(
        INCLUDES source/impl/ethermind/controller/configs/mbedtls
        TARGET_FILES mbedtls_config_client.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/controller/configs/mbedtls/mbedtls_config_client.h
        CONFIG TRUE
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.porting)
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_include(
        INCLUDES source/porting
    )
    mcux_add_source(
        SOURCES include/sys/util.h
    )
    mcux_add_source(
        SOURCES include/sys/util_internal.h
    )
    mcux_add_source(
        SOURCES include/sys/util_loops.h
    )
    mcux_add_source(
        SOURCES include/sys/util_macro.h
    )
    mcux_add_source(
        SOURCES include/sys/printk.h
    )
    mcux_add_source(
        SOURCES include/sys/check.h
    )
    mcux_add_source(
        SOURCES include/sys/byteorder.h
    )
    mcux_add_source(
        SOURCES include/zephyr/types.h
    )
    mcux_add_source(
        SOURCES include/sys/ring_buffer.h
    )
    mcux_add_source(
        SOURCES include/sys/ffs.h
    )
    mcux_add_source(
        SOURCES source/porting/ring_buffer.c
    )
    mcux_add_source(
        SOURCES source/porting/porting.c
    )
    mcux_add_source(
        SOURCES source/porting/porting.h
    )
    mcux_add_source(
        SOURCES source/porting/system_c.h
    )
    mcux_add_source(
        SOURCES source/porting/errno/errno.h
    )
    mcux_add_source(
        SOURCES source/porting/utf8.c
    )
    mcux_add_source(
        SOURCES source/porting/fifo/fifo.c
    )
    mcux_add_source(
        SOURCES source/porting/fifo/fifo.h
    )
    mcux_add_source(
        SOURCES source/porting/lifo/lifo.c
    )
    mcux_add_source(
        SOURCES source/porting/lifo/lifo.h
    )
    mcux_add_source(
        SOURCES source/porting/poll/poll.c
    )
    mcux_add_source(
        SOURCES source/porting/poll/poll.h
    )
    mcux_add_source(
        SOURCES source/porting/queue/queue.c
    )
    mcux_add_source(
        SOURCES source/porting/queue/queue.h
    )
    mcux_add_source(
        SOURCES source/porting/sem/sem.c
    )
    mcux_add_source(
        SOURCES source/porting/sem/sem.h
    )
    mcux_add_source(
        SOURCES source/porting/slab/slab.c
    )
    mcux_add_source(
        SOURCES source/porting/slab/slab.h
    )
    mcux_add_source(
        SOURCES source/porting/slist/slist.c
    )
    mcux_add_source(
        SOURCES source/porting/spinlock/spinlock.h
    )
    mcux_add_source(
        SOURCES source/porting/thread/thread.c
    )
    mcux_add_source(
        SOURCES source/porting/thread/thread.h
    )
    mcux_add_configuration(
        CC "-DLOG_ENABLE_ASYNC_MODE=1 -DLOG_MAX_ARGUMENT_COUNT=10 -DLOG_ENABLE_OVERWRITE=0"
        CX "-DLOG_ENABLE_ASYNC_MODE=1 -DLOG_MAX_ARGUMENT_COUNT=10 -DLOG_ENABLE_OVERWRITE=0"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.shell)
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_include(
        INCLUDES source/shell
    )
    mcux_add_source(
        SOURCES source/shell/shell_bt.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_bt.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_bredr.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_gatt.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_hci.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_hci.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_l2cap.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_rfcomm.c
    )
    mcux_add_source(
        SOURCES source/shell/fsl_shell.c
    )
    mcux_add_source(
        SOURCES source/shell/fsl_shell.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_a2dp.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_avrcp.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_test_mode.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_test_mode.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_iso.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_map.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_pbap.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_hfp.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_ble_scan_filter.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_ble_scan_filter.h
    )
    mcux_add_configuration(
        CC "-DSHELL_ADVANCE=1 -DDEBUG_CONSOLE_RX_ENABLE=0 -DOSA_USED=1 -DSHELL_USE_COMMON_TASK=0"
        CX "-DSHELL_ADVANCE=1 -DDEBUG_CONSOLE_RX_ENABLE=0 -DOSA_USED=1 -DSHELL_USE_COMMON_TASK=0"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.controller_ind_reset)
    mcux_add_include(
        INCLUDES source/impl/ethermind/controller/ind_reset
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/controller/ind_reset/controller_ind_reset.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/controller/ind_reset/controller_ind_reset.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.host_low_power)
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}
        SOURCES
            examples/common/project_segments/wireless/rw61x/low_power/board_lp.c
            examples/common/project_segments/wireless/rw61x/low_power/board_lp.h
        DEVICE_IDS RW612 RW610
    )
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}
        INCLUDES examples/common/project_segments/wireless/rw61x/low_power
        DEVICE_IDS RW612 RW610
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}
        SOURCES examples/common/project_segments/wireless/rw61x/app_common/app_services_init.c
        DEVICE_IDS RW612 RW610
    )
    mcux_add_include(
        BASE_PATH ${SdkRootDirPath}
        INCLUDES examples/${board}
        DEVICE_IDS MIMXRT595S
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}
        SOURCES examples/${board}/fwk_board_lp.h
        DEVICE_IDS MIMXRT595S
    )
    mcux_add_source(
        BASE_PATH ${SdkRootDirPath}
        SOURCES examples/${board}/fwk_board_lp.c
        DEVICE_IDS MIMXRT595S
    )
    mcux_add_source(
        SOURCES low_power/host/${board}/host_low_power.c
        DEVICE_IDS MIMXRT595S
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.controller_low_power)
    mcux_add_include(
        INCLUDES low_power/controller
    )
    mcux_add_source(
        SOURCES low_power/controller/controller_low_power.h
    )
    mcux_add_source(
        SOURCES low_power/controller/controller_low_power.c
    )
    mcux_add_source(
        SOURCES low_power/controller/controller_low_power_config.h
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.shell.le_audio)
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_include(
        INCLUDES source/shell
    )
    mcux_add_include(
        INCLUDES source/impl/ethermind/audio/shell
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/audio.h
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/bap_broadcast_assistant.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/bap_scan_delegator.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/bap.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/cap_acceptor.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/cap_commander.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/cap_initiator.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/csip_set_coordinator.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/csip_set_member.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/has_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/has.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/mcc.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/media_controller.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/micp_mic_ctlr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/micp_mic_dev.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/mpl.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/tbs_client.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/tbs.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/tmap.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/gmap.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/pbp.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/vcp_vol_ctlr.c
    )
    mcux_add_source(
        SOURCES source/impl/ethermind/audio/shell/vcp_vol_rend.c
    )
    mcux_add_configuration(
        CC "-DSHELL_ADVANCE=1 -DDEBUG_CONSOLE_RX_ENABLE=0 -DOSA_USED=1 -DSHELL_USE_COMMON_TASK=0"
        CX "-DSHELL_ADVANCE=1 -DDEBUG_CONSOLE_RX_ENABLE=0 -DOSA_USED=1 -DSHELL_USE_COMMON_TASK=0"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.liblc3codec)
    mcux_add_include(
        INCLUDES lib/liblc3codec/include
    )
    mcux_add_include(
        INCLUDES lib/liblc3codec
    )
    mcux_add_include(
        INCLUDES lib
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/include/lc3.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/include/lc3_private.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/attdet.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/attdet.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/bits.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/bits.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/bwdet.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/bwdet.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/common.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/energy.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/energy.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/lc3.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/ltpf.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/ltpf.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/mdct.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/mdct.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/plc.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/plc.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/sns.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/sns.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/spec.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/spec.h
    )
    mcux_add_source(
        SOURCES lib/iblc3codec/src/tables.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/tables.h
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/tns.c
    )
    mcux_add_source(
        SOURCES lib/liblc3codec/src/tns.h
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.asrc_sw)
    mcux_add_include(
        INCLUDES lib/asrc_sw/include
    )
    mcux_add_include(
        INCLUDES lib/asrc_sw
    )
    mcux_add_include(
        INCLUDES lib
    )
    mcux_add_source(
        SOURCES lib/asrc_sw/srCvtFrm.h
    )
    mcux_add_source(
        SOURCES lib/asrc_sw/srCvtFrm.c
    )
    mcux_add_source(
        SOURCES lib/asrc_sw/downSmplAllRates.dat
    )
    mcux_add_source(
        SOURCES lib/asrc_sw/upSmpl_32_32_rev.dat
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.shell_ble)
    mcux_add_include(
        INCLUDES include
    )
    mcux_add_include(
        INCLUDES source/shell
    )
    mcux_add_source(
        SOURCES source/shell/shell_bt.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_bt.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_gatt.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_hci.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_hci.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_l2cap.c
    )
    mcux_add_source(
        SOURCES source/shell/fsl_shell.c
    )
    mcux_add_source(
        SOURCES source/shell/fsl_shell.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_test_mode.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_test_mode.h
    )
    mcux_add_source(
        SOURCES source/shell/shell_ble_scan_filter.c
    )
    mcux_add_source(
        SOURCES source/shell/shell_ble_scan_filter.h
    )
    mcux_add_configuration(
        CC "-DSHELL_ADVANCE=1 -DDEBUG_CONSOLE_RX_ENABLE=0 -DOSA_USED=1 -DSHELL_USE_COMMON_TASK=0"
        CX "-DSHELL_ADVANCE=1 -DDEBUG_CONSOLE_RX_ENABLE=0 -DOSA_USED=1 -DSHELL_USE_COMMON_TASK=0"
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.btble.ethermind.lib)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_a2dp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_avrcp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_bip.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_bpp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_core.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_ctn.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_ftp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_ga.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_gatt.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_hfp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_hid.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_map.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_opp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_pan.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_pbap.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_protocol.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_sap.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_spp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_bt_util.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_sbc_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_sbc_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_sbc_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_a2dp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_avrcp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_bip.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_bpp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_core.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_ctn.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_ftp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_ga.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_gatt.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_hfp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_hid.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_map.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_opp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_pan.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_pbap.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_protocol.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_sap.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_spp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_bt_util.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_sbc_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_sbc_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_sbc_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_a2dp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_avrcp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_bip.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_bpp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_core.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_ctn.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_ftp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_core_arch}/mcuxpresso/libethermind_bt_ga.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_gatt.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_hfp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_hid.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_map.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_opp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_pan.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_pbap.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_protocol.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_sap.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_spp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_bt_util.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_sbc_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_sbc_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_sbc_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_a2dp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_avrcp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_bip.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_bpp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_core.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_ctn.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_ftp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_ga.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_gatt.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_hfp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_hid.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_map.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_opp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_pan.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_pbap.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_protocol.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_sap.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_spp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_bt_util.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_sbc_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_sbc_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_sbc_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.br.ethermind.lib)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_a2dp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_avrcp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_bip.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_bpp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_core.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_ctn.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_ftp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_hfp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_hid.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_map.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_opp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_pan.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_pbap.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_protocol.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_sap.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_spp.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_util.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_sbc_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_sbc_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/gcc/libethermind_br_sbc_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_a2dp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_avrcp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_bip.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_bpp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_core.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_ctn.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_ftp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_hfp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_hid.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_map.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_opp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_pan.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_pbap.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_protocol.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_sap.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_spp.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_util.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_sbc_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_sbc_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/iar/libethermind_br_sbc_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_a2dp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_avrcp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_bip.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_bpp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_core.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_ctn.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_ftp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_hfp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_hid.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_map.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_opp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_pan.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_pbap.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_protocol.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_sap.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_spp.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_util.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_sbc_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_sbc_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mcuxpresso/libethermind_br_sbc_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_a2dp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_avrcp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_bip.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_bpp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_core.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_ctn.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_ftp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_hfp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_hid.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_map.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_opp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_pan.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_pbap.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_protocol.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_sap.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_spp.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_util.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_sbc_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_sbc_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/br/${wireless_ble_lib_sel}/mdk/libethermind_br_sbc_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.ble.ethermind.lib)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_ble_core.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_ble_gatt.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_ble_protocol.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_ble_util.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_ble_ga.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_ble_core.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_ble_gatt.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_ble_protocol.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_ble_util.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_ble_ga.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_ble_core.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_ble_gatt.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_ble_protocol.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_ble_util.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_ble_ga.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_ble_core.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_ble_gatt.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_ble_protocol.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_ble_util.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_ble_ga.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.btble.ethermind.lib.lc3)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_lc3_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_lc3_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_lc3_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_lc3_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_lc3_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_lc3_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_lc3_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_lc3_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_lc3_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.br.ethermind.lib.lc3)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_lc3_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_lc3_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/gcc/libethermind_lc3_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_lc3_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_lc3_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/iar/libethermind_lc3_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_lc3_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_lc3_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/${wireless_ble_lib_sel}/mdk/libethermind_lc3_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.ble.ethermind.lib.lc3)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_lc3_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_lc3_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/gcc/libethermind_lc3_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_lc3_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_lc3_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/iar/libethermind_lc3_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mcuxpresso/libethermind_lc3_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_lc3_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_lc3_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/${wireless_ble_lib_sel}/mdk/libethermind_lc3_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.btble.ethermind.lib.lc3_nodsp)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/gcc/libethermind_lc3_ndsp_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/gcc/libethermind_lc3_ndsp_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/gcc/libethermind_lc3_ndsp_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/iar/libethermind_lc3_ndsp_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/iar/libethermind_lc3_ndsp_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/iar/libethermind_lc3_ndsp_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/mcuxpresso/libethermind_lc3_ndsp_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/mcuxpresso/libethermind_lc3_ndsp_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/mcuxpresso/libethermind_lc3_ndsp_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/mdk/libethermind_lc3_ndsp_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/mdk/libethermind_lc3_ndsp_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/btdm/cm33nodsp/mdk/libethermind_lc3_ndsp_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_COMPONENT_middleware.edgefast_bluetooth.ble.ethermind.lib.lc3_nodsp)
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/gcc/libethermind_ble_lc3_ndsp_common.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/gcc/libethermind_ble_lc3_ndsp_decoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/gcc/libethermind_ble_lc3_ndsp_encoder.a
        TOOLCHAINS armgcc
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/iar/libethermind_ble_lc3_ndsp_common.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/iar/libethermind_ble_lc3_ndsp_decoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/iar/libethermind_ble_lc3_ndsp_encoder.a
        TOOLCHAINS iar
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/mcuxpresso/libethermind_ble_lc3_ndsp_decoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/mcuxpresso/libethermind_ble_lc3_ndsp_encoder.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/mcuxpresso/libethermind_ble_lc3_ndsp_common.a
        TOOLCHAINS mcux
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/mdk/libethermind_ble_lc3_ndsp_common.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/mdk/libethermind_ble_lc3_ndsp_decoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
    mcux_add_library(
        LIBS ../wireless/ethermind/bluetooth/private/lib/mcux/default/ble/cm33nodsp/mdk/libethermind_ble_lc3_ndsp_encoder.lib
        TOOLCHAINS mdk
        CORES ${wireless_ble_core_arch}
        DSP ${wireless_ble_lib_sel_dsp}
    )
endif ()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.storage)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth_flash_adapter_rt1170evkb)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth_flash_adapter_rt685evk)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth_flash_adapter_rt595evk)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth_mflash_offchip)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth_mflash_onchip_fmu)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_wm8962)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_sai_edma)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_wm8960)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_wm8904)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_cs42448)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_dialog7212)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.codec_i2s_dma)
endif()

if (CONFIG_MCUX_PRJSEG_middleware.edgefast_bluetooth.low_power)
endif()