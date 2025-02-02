/*
 * Copyright 2020-2023 NXP
 *  All rights reserved.
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 */

#include "edgefast_bluetooth_config_Gen.h"
#include "edgefast_bluetooth_extension_config_Gen.h"

/* Controller config
 * Supported controller list,
 * WIFI_IW416_BOARD_MURATA_1XK_M2
 * WIFI_88W8987_BOARD_MURATA_1ZM_M2
 * WIFI_IW612_BOARD_MURATA_2EL_M2
 * If Murata Type 1XK module used, define macro WIFI_IW416_BOARD_MURATA_1XK_M2 in following.
 * If Murata Type 1ZM module used, define macro WIFI_88W8987_BOARD_MURATA_1ZM_M2 in following.
 * If Murata Type 2EL module used , define macro WIFI_IW612_BOARD_MURATA_2EL_M2 in following. 
 */

/* @TEST_ANCHOR */
#define WIFI_IW612_BOARD_MURATA_2EL_M2
/* @END_TEST_ANCHOR */
/*#define WIFI_IW416_BOARD_MURATA_1XK_M2*/
/*#define WIFI_88W8987_BOARD_MURATA_1ZM_M2*/
/*#define WIFI_IW612_BOARD_MURATA_2EL_M2*/

#if defined(WIFI_IW416_BOARD_MURATA_1XK_M2) || defined(WIFI_88W8987_BOARD_MURATA_1ZM_M2) || \
    defined(WIFI_IW612_BOARD_MURATA_2EL_M2)  || defined(WIFI_88W8987_BOARD_AW_CM358_USD)  || \
    defined(WIFI_IW416_BOARD_AW_AM510MA)  || defined(WIFI_IW416_BOARD_AW_AM510_USD) ||  \
    defined(WIFI_IW416_BOARD_AW_AM457_USD)  || defined(WIFI_88W8987_BOARD_AW_CM358MA) || \
    defined(WIFI_88W8987_BOARD_AW_CM358_MA)
#include "wifi_bt_module_config.h"
#include "wifi_config.h"
#else
#error The transceiver module is unsupported
#endif

#if defined(WIFI_IW612_BOARD_MURATA_2EL_M2)
#undef SD_TIMING_MAX
#define SD_TIMING_MAX kSD_TimingDDR50Mode
#endif /*#define WIFI_IW612_BOARD_MURATA_2EL_M2*/

/* Select witch beacon application to start */
#define BEACON_APP  1
#define IBEACON_APP 0
#define EDDYSTONE   0

#if (defined EDDYSTONE) && (EDDYSTONE)
#undef CONFIG_BT_SETTINGS
#define CONFIG_BT_SETTINGS              1
#undef CONFIG_BT_KEYS_OVERWRITE_OLDEST
#define CONFIG_BT_KEYS_OVERWRITE_OLDEST 1
#endif
#if defined(IBEACON_APP) && (IBEACON_APP == 1)
#undef CONFIG_BT_DEVICE_NAME
#define CONFIG_BT_DEVICE_NAME "ibeacon"
#elif defined(EDDYSTONE) && (EDDYSTONE == 1)
#undef CONFIG_BT_DEVICE_NAME
#define CONFIG_BT_DEVICE_NAME "eddystone"
#elif defined(BEACON_APP) && (BEACON_APP == 1)
#undef CONFIG_BT_DEVICE_NAME
#define CONFIG_BT_DEVICE_NAME "beacon"
#endif
        
