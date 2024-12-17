# EdgeFast BT PAL configuration documentation

**CONFIG\_BT\_BUF\_RESERVE**

Buffer reserved length, suggested value is 8.

**CONFIG\_BT\_SNOOP**

Whether enable bt snoop feature, 0 - disable, 1 - enable.

**CONFIG\_BT\_HCI\_CMD\_COUNT**

Number of HCI command buffers, ranging from 2 to 64. Number of buffers available for HCI commands Range 2 to 64 is valid.

**CONFIG\_BT\_RX\_BUF\_COUNT**

Number of HCI RX buffers, ranging from 2 to 255. Number of buffers available for incoming ACL packets or HCI events from the controller Range 2 to 255 is valid.

**CONFIG\_BT\_RX\_BUF\_LEN**

Maximum supported HCI RX buffer length, ranging from 73 to 2000. Maximum data size for each HCI RX buffer. This size includes everything starting with the ACL or HCI event headers. Note that buffer sizes are always rounded up to the nearest multiple of 4, so if this Kconfig value is something else then there is some wasted space. The minimum of 73 has been taken for LE SC which has an L2CAP MTU of 65 bytes. On top of this, The L2CAP header \(4 bytes\) and the ACL header \(also 4 bytes\) which yields 73 bytes. Range is 73 to 2000.

**CONFIG\_BT\_HCI\_RESERVE**

Reserve buffer size for user. Headroom that the driver needs for sending and receiving buffers. Add a new ‘default’ entry for each new driver.

**CONFIG\_BT\_DISCARDABLE\_BUF\_COUNT**

Number of discardable event buffers, if the macro is set to 0, disable this feature, if greater than 0, this feature is enabled. Number of buffers in a separate buffer pool for events which the HCI driver considers discardable. Examples of such events could be , for example, Advertising Reports. The benefit of having such a pool means that if there is a heavy inflow of such events it does not cause the allocation for other critical events to block and may even eliminate deadlocks in some cases.

**CONFIG\_BT\_DISCARDABLE\_BUF\_SIZE**

Size of discardable event buffers, ranging from 45 to 257. Size of buffers in the separate discardable event buffer pool. The minimum size is set based on the Advertising Report. Setting the buffer can save memory if with size set differently from that of the CONFIG\_BT\_RX\_BUF\_LEN. range is 45 to 257.

**CONFIG\_BT\_HCI\_TX\_STACK\_SIZE**

HCI TX task stack size needed for executing bt\_send with specified driver, should be no less than 512.

**CONFIG\_BT\_HCI\_TX\_PRIO**

HCI TX task priority.

**CONFIG\_BT\_RX\_STACK\_SIZE**

Size of the receiving thread stack. This is the context from which all event callbacks to the application occur. The default value is sufficient for basic operation, but if the application needs to do advanced things in its callbacks that require extra stack space, this value can be increased to accommodate for that.

**CONFIG\_BT\_RX\_PRIO**

RX task priority.

**CONFIG\_BT\_PERIPHERAL**

Peripheral Role support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. Select this for LE Peripheral role support.

**CONFIG\_BT\_BROADCASTER**

Broadcaster Role support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. Select this for LE Broadcaster role support.

**CONFIG\_BT\_EXT\_ADV**

Extended Advertising and Scanning support \[EXPERIMENTAL\], if the macro is set to 0, feature is disabled, if 1, feature is enabled. Select this to enable Extended Advertising API support. This enables support for advertising with multiple advertising sets, extended advertising data, and advertising on LE Coded PHY. It enables support for receiving extended advertising data as a scanner, including support for advertising data over the LE coded PHY. It enables establishing connections over LE Coded PHY.

**CONFIG\_BT\_CENTRAL**

Central Role support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. Select this for LE Central role support.

**CONFIG\_BT\_WHITELIST**

Enable whitelist support. This option enables the whitelist API. This takes advantage of the whitelisting feature of a Bluetooth LE controller. The whitelist is a global list and the same whitelist is used by both scanner and advertiser. The whitelist cannot be modified while it is in use. An Advertiser can whitelist which peers can connect or request scan response data. A scanner can whitelist advertiser for which it generates advertising reports. Connections can be established automatically for whitelisted peers.

This option deprecates the bt\_le\_set\_auto\_conn API in favor of the bt\_conn\_create\_aute\_le API.

**CONFIG\_BT\_DEVICE\_NAME**

Bluetooth device name. Name can be up to 248 bytes long \(excluding NULL termination\). Can be empty string.

**CONFIG\_BT\_DEVICE\_APPEARANCE**

Bluetooth device appearance. For the list of possible values, see the link: www.bluetooth.com/specifications/assigned-numbers.

**CONFIG\_BT\_DEVICE\_NAME\_DYNAMIC**

Allow to set Bluetooth device name on runtime. Enabling this option allows for runtime configuration of Bluetooth device name.

**CONFIG\_BT\_ID\_MAX**

Maximum number of local identities, range 1 to 10 is valid. Maximum number of supported local identity addresses. For most products, this is safe to leave as the default value \(1\). Range 1 to 10 is valid.

**CONFIG\_BT\_CONN**

Connection enablement, if the macro is set to 0, feature is disabled, if 1, feature is enabled.

**CONFIG\_BT\_MAX\_CONN**

it is the max connection supported by host stack. Maximum number of simultaneous Bluetooth connections supported.

**CONFIG\_BT\_HCI\_ACL\_FLOW\_CONTROL**

Controller to host ACL flow control support. Enable support for throttling ACL buffers from the controller to the host. This is useful when the host and controller are on separate cores, since it ensures that we do not run out of incoming ACL buffers.

**CONFIG\_BT\_PHY\_UPDATE**

PHY Update, if the macro is set to 0, feature is disabled, if 1, feature is enabled. Enable support for Bluetooth 5.0 PHY Update Procedure.

**CONFIG\_BT\_DATA\_LEN\_UPDATE**

Data Length Update. If the macro is set to 0, feature is disabled, if 1, feature is enabled. Enable support for Bluetooth v4.2 LE Data Length Update procedure.

**CONFIG\_BT\_CREATE\_CONN\_TIMEOUT**

Timeout for pending LE Create Connection command in seconds.

**CONFIG\_BT\_CONN\_PARAM\_UPDATE\_TIMEOUT**

Peripheral connection parameter update timeout in milliseconds, range 1 to 65535 is valid. The value is a timeout used by peripheral device to wait until it starts the connection parameters update procedure to change default connection parameters. The default value is set to 5s, to comply with BT protocol specification: Core 4.2 Vol 3, Part C, 9.3.12.2 Range 1 to 65535 is valid.

**CONFIG\_BT\_CONN\_TX\_MAX**

Maximum number of pending TX buffers. Maximum number of pending TX buffers that have not yet been acknowledged by the controller.

**CONFIG\_BT\_REMOTE\_INFO**

Enable application access to remote information. Enable application access to the remote information available in the stack. The remote information is retrieved once a connection has been established and the application is notified when this information is available through the remote\_version\_available connection callback.

**CONFIG\_BT\_REMOTE\_VERSION**

Enable fetching of remote version. Enable this to get access to the remote version in the Controller and in the host through bt\_conn\_get\_info\(\). The fields in question can be then found in the bt\_conn\_info struct.

**CONFIG\_BT\_SMP\_SC\_ONLY**

Secure Connections Only Mode. This option enables support for Secure Connection Only Mode. In this mode device shall only use Security Mode 1 Level 4 with exception for services that only require Security Mode 1 Level 1 \(no security\). Security Mode 1 Level 4 stands for authenticated LE Secure Connections pairing with encryption. Enabling this option disables legacy pairing.

**CONFIG\_BT\_SMP\_OOB\_LEGACY\_PAIR\_ONLY**

Force Out of Band Legacy pairing. This option disables Legacy and LE SC pairing and forces legacy OOB.

**CONFIG\_BT\_SMP\_DISABLE\_LEGACY\_JW\_PASSKEY**

Forbid usage of insecure legacy pairing methods. This option disables Just Works and Passkey legacy pairing methods to increase security.

**CONFIG\_BT\_PRIVACY**

Privacy Feature, if the macro is set to 0, feature is disabled, if 1, feature is enabled. Enable local Privacy Feature support. This makes it possible to use Resolvable Private Addresses \(RPAs\).

**CONFIG\_BT\_ECC**

Enable ECDH key generation support. This option adds support for ECDH HCI commands.

**CONFIG\_BT\_TINYCRYPT\_ECC**

Use TinyCrypt library for ECDH. If this option is used to set TinyCrypt library which is used for emulating the ECDH HCI commands and events needed by e.g. LE Secure Connections. In builds including the Bluetooth LE host, if don’t set the controller crypto which is used for ECDH and if the controller doesn’t support the required HCI commands the LE Secure Connections support will be disabled. In builds including the HCI Raw interface and the Bluetooth LE controller, this option injects support for the 2 HCI commands required for LE Secure Connections so that hosts can make use of those. The option defaults to enabled for a combined build with Zephyr’s own controller, since it does not have any special ECC support itself \(at least not currently\).

**CONFIG\_BT\_TINYCRYPT\_ECC\_PRIORITY**

Thread priority of ECC Task.

**CONFIG\_BT\_HCI\_ECC\_STACK\_SIZE**

Thread stack size of ECC Task.

**CONFIG\_BT\_RPA**

Bluetooth Resolvable Private Address \(RPA\)

**CONFIG\_BT\_RPA\_TIMEOUT**

Resolvable Private Address timeout, defaults to 900 seconds. This option defines how often resolvable private address is rotated. Value is provided in seconds and defaults to 900 seconds \(15 minutes\).

**CONFIG\_BT\_SIGNING**

Data signing support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables data signing which is used for transferring authenticated data in an unencrypted connection.

**CONFIG\_BT\_SMP\_APP\_PAIRING\_ACCEPT**

Accept or reject pairing initiative. When receiving pairing request or pairing response queries, the application shall either accept proceeding with pairing or not. This is for pairing over SMP and does not affect SSP, which will continue pairing without querying the application. The application can return an error code, which is translated into an SMP return value if the pairing is not allowed.

**CONFIG\_BT\_SMP\_ALLOW\_UNAUTH\_OVERWRITE**

Allow unauthenticated pairing for paired device. This option allows all unauthenticated pairing attempts made by the peer where an unauthenticated bond already exists. This would enable cases where an attacker could copy the peer device address to connect and start an unauthenticated pairing procedure to replace the existing bond. When this option is disabled in order to create a new bond the old bond must be explicitly deleted with bt\_unpair.

**CONFIG\_BT\_FIXED\_PASSKEY**

Use a fixed passkey for pairing, set passkey to fixed or not. With this option enabled, the application will be able to call the bt\_passkey\_set\(\) API to set a fixed passkey. If set, the pairing\_confim\(\) callback will be called for all incoming pairings.

**CONFIG\_BT\_BONDABLE**

Bondable Mode, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables support for Bondable Mode. In this mode, Bonding flag in AuthReq of SMP Pairing Request/Response is set indicating the support for this mode.

**CONFIG\_BT\_BONDING\_REQUIRED**

Always require bonding. When this option is enabled remote devices are required to always set the bondable flag in their pairing request. Any other kind of requests will be rejected.

**CONFIG\_BT\_SMP\_ENFORCE\_MITM**

Enforce MITM protection, if the macro is set to 0, feature is disabled, if 1, feature is enabled. With this option enabled, the Security Manager is set MITM option in the Authentication Requirements Flags whenever local IO Capabilities allow the generated key to be authenticated.

**CONFIG\_BT\_OOB\_DATA\_FIXED**

Use a fixed random number for LESC OOB pairing. With this option enabled, the application will be able to perform LESC pairing with OOB data that consists of fixed random number and confirm value. This option should only be enabled for debugging and should never be used in production.

**CONFIG\_BT\_KEYS\_OVERWRITE\_OLDEST**

Overwrite oldest keys with new ones if key storage is full. With this option enabled, if a pairing attempt occurs and the key storage is full, then the oldest keys in storage will be removed to free space for the new pairing keys.

**CONFIG\_BT\_HOST\_CCM**

Enable host side AES-CCM module. Enables the software-based AES-CCM engine in the host. Will use the controller’s AES encryption functions if available, or BT\_HOST\_CRYPTO otherwise.

**CONFIG\_BT\_L2CAP\_RX\_MTU**

Maximum supported L2CAP MTU for incoming data, if CONFIG\_BT\_SMP is set, range is 65 to 1300, otherwise range is 23 to 1300. Maximum size of each incoming L2CAP PDU. Range is 23 to 1300 range is 65 to 1300 for CONFIG\_BT\_SMP.

**CONFIG\_BT\_L2CAP\_TX\_BUF\_COUNT**

Number of buffers available for outgoing L2CAP packets, ranging from 2 to 255. Range is 2 to 255.

**CONFIG\_BT\_L2CAP\_TX\_FRAG\_COUNT**

Number of L2CAP TX fragment buffers, ranging from 0 to 255. Number of buffers available for fragments of TX buffers.

Warning: Setting this to 0 means that the application must ensure that queued TX buffers never need to be fragmented, that is the controller’s buffer size is large enough. If this is not ensured, and there are no dedicated fragment buffers, a deadlock may occur. In most cases the default value of 2 is a safe bet. Range is 0 to 255.

**CONFIG\_BT\_L2CAP\_TX\_MTU**

Maximum supported L2CAP MTU for L2CAP TX buffers, if CONFIG\_BT\_SMP is set, the range is 65 to 2000. Otherwise, range is 23 to 2000. Range is 23 to 2000. Range is 65 to 2000 for CONFIG\_BT\_SMP.

**CONFIG\_BT\_L2CAP\_DYNAMIC\_CHANNEL**

L2CAP Dynamic Channel support. This option enables support for LE Connection oriented Channels, allowing the creation of dynamic L2CAP Channels.

**CONFIG\_BT\_L2CAP\_DYNAMIC\_CHANNEL**

L2CAP Dynamic Channel support. This option enables support for LE Connection oriented Channels, allowing the creation of dynamic L2CAP Channels.

Bluetooth BR/EDR support \[EXPERIMENTAL\] This option enables Bluetooth BR/EDR support.

**CONFIG\_BT\_ATT\_PREPARE\_COUNT**

Number of ATT prepares write buffers, if the macro is set to 0, feature is disabled, if greater than 1, feature is enabled. Number of buffers available for ATT prepares write, setting this to 0 disables GATT long/reliable writes.

**CONFIG\_BT\_ATT\_TX\_MAX**

Maximum number of queued outgoing ATT PDUs. Number of ATT PDUs that can be at a single moment queued for transmission. If the application tries to send more than this amount the calls blocks until an existing queued PDU gets sent. Range is 1 to CONFIG\_BT\_L2CAP\_TX\_BUF\_COUNT.

**CONFIG\_BT\_GATT\_SERVICE\_CHANGED**

GATT Service Changed support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables support for the service changed characteristic.

**CONFIG\_BT\_GATT\_DYNAMIC\_DB**

GATT dynamic database support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables registering/unregistering services at runtime.

**CONFIG\_BT\_GATT\_CACHING**

GATT Caching support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables support for GATT Caching. When enabled the stack registers Client Supported Features and Database Hash characteristics which is used by clients to detect if anything has changed on the GATT database.

**CONFIG\_BT\_GATT\_CLIENT**

GATT client support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables support for the GATT Client role.

**CONFIG\_BT\_GATT\_READ\_MULTIPLE**

GATT Read Multiple Characteristic. Values support, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables support for the GATT Read Multiple Characteristic Values procedure.

**CONFIG\_BT\_GAP\_AUTO\_UPDATE\_CONN\_PARAMS**

Automatic Update of Connection Parameters, if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option, if enabled, allows automatically sending request for connection parameters update after GAP recommended 5 seconds of connection as peripheral.

**CONFIG\_BT\_GAP\_PERIPHERAL\_PREF\_PARAMS**

Configure peripheral preferred connection parameters. This configures peripheral preferred connection parameters. Enabling this option results in adding PPCP characteristic in GAP. If disabled it is up to application to set expected connection parameters.

**CONFIG\_BT\_MAX\_PAIRED**

Maximum number of paired devices. Maximum number of paired Bluetooth devices. The minimum \(and default\) number is 1.

**CONFIG\_BT\_MAX\_SCO\_CONN**

Maximum number of simultaneous SCO connections. Maximum number of simultaneous Bluetooth synchronous connections supported. The minimum \(and default\) number is 1. Range 1 to 3 is valid.

**CONFIG\_BT\_RFCOMM**

Bluetooth RFCOMM protocol support \[EXPERIMENTAL\], if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables Bluetooth RFCOMM support.

**CONFIG\_BT\_RFCOMM\_L2CAP\_MTU**

L2CAP MTU for RFCOMM frames. Maximum size of L2CAP PDU for RFCOMM frames.

**CONFIG\_BT\_HFP\_HF**

Bluetooth Handsfree profile HF Role support \[EXPERIMENTAL\], if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables Bluetooth HF support.

**CONFIG\_BT\_AVDTP**

Bluetooth AVDTP protocol support \[EXPERIMENTAL\], if the macro is set to 0, feature is disabled, if 1, feature is enabled. This option enables Bluetooth AVDTP support.

**CONFIG\_BT\_A2DP**

Bluetooth A2DP Profile \[EXPERIMENTAL\]. This option enables the A2DP profile.

**CONFIG\_BT\_A2DP\_SOURCE**

Bluetooth A2DP profile source function. This option enables the A2DP profile Source function.

**CONFIG\_BT\_A2DP\_SINK**

Bluetooth A2DP profile sink function. This option enables the A2DP profile Sink function.

**CONFIG\_BT\_A2DP\_TASK\_PRIORITY**

Bluetooth A2DP profile task priority. This option sets the task priority. The task is used to process the streamer data and retry command.

**CONFIG\_BT\_A2DP\_TASK\_STACK\_SIZE**

Bluetooth A2DP profile task stack size. This option sets the task stack size.

**CONFIG\_BT\_PAGE\_TIMEOUT**

Bluetooth Page Timeout. This option sets the page timeout value. Value is selected as \(N \* 0.625\) ms.

**CONFIG\_BT\_DIS\_MODEL**

Model name. The device model inside Device Information Service.

**CONFIG\_BT\_DIS\_MANUF**

Manufacturer name. The device manufacturer inside Device Information Service.

**CONFIG\_BT\_DIS\_PNP**

Enable PnP\_ID characteristic. Enable PnP\_ID characteristic in Device Information Service.

**CONFIG\_BT\_DIS\_PNP\_VID\_SRC**

Vendor ID source, range 1 - 2. The Vendor ID Source field designates which organization assigned the value used in the Vendor ID field value. The possible values are:

-   1 Bluetooth SIG, the Vendor ID was assigned by the Bluetooth SIG
-   2 USB IF, the Vendor ID was assigned by the USB IF

**CONFIG\_BT\_DIS\_PNP\_VID**

Vendor ID, range 0 - 0xFFFF. The Vendor ID field is intended to uniquely identify the vendor of the device. This field is used in conjunction with Vendor ID Source field, which determines which organization assigned the Vendor ID field value. Note: The Bluetooth Special Interest Group assigns Device ID Vendor ID, and the USB Implementers Forum assigns Vendor IDs, either of which can be used for the Vendor ID field value. Device providers should procure the Vendor ID from the USB Implementers Forum or the Company Identifier from the Bluetooth SIG.

**CONFIG\_BT\_DIS\_PNP\_PID**

Product ID, range 0 - 0xFFFF. The Product ID field is intended to distinguish between different products made by the vendor identified with the Vendor ID field. The vendors themselves manage Product ID field values.

**CONFIG\_BT\_DIS\_PNP\_VER**

Product Version, range 0 - 0xFFFF. The Product Version field is a numeric expression identifying the device release number in Binary-Coded Decimal. This is a vendor-assigned value, which defines the version of the product identified by the Vendor ID and Product ID fields. This field is intended to differentiate between versions of products with identical Vendor IDs and Product IDs. The value of the field value is 0xJJMN for version JJ.M.N \(JJ - major version number, M - minor version number, N - subminor version number\); For example, version 2.1.3 is represented with value 0x0213 and version 2.0.0 is represented with a value of 0x0200. When upward-compatible changes are made to the device, it is recommended that the minor version number be incremented. If incompatible changes are made to the device. It is recommended that the major version number is incremented. The subminor version is incremented for bug fixes.

**CONFIG\_BT\_DIS\_SERIAL\_NUMBER**

Enable DIS Serial number characteristic, 1 - enable, 0 - disable. Enable Serial Number characteristic in Device Information Service.

**CONFIG\_BT\_DIS\_SERIAL\_NUMBER\_STR**

Serial Number. Serial Number characteristic string in Device Information Service.

**CONFIG\_BT\_DIS\_FW\_REV**

Enable DIS Firmware Revision characteristic, 1 - enable, 0 - disable. Enable Firmware Revision characteristic in Device Information Service.

**CONFIG\_BT\_DIS\_FW\_REV\_STR**

Firmware revision. Firmware Revision characteristic String in Device Information Service.

**CONFIG\_BT\_DIS\_HW\_REV**

Enable DIS Hardware Revision characteristic, 1 - enable, 0 - disable. Enable Hardware Revision characteristic in Device Information Service.

**CONFIG\_BT\_DIS\_HW\_REV\_STR**

Hardware revision. Hardware Revision characteristic String in Device Information Service.

**CONFIG\_BT\_DIS\_SW\_REV**

Enable DIS Software Revision characteristic, 1 - enable, 0 - disable. Enable Software Revision characteristic in Device Information Service.

**CONFIG\_BT\_DIS\_SW\_REV\_STR**

Software revision Software revision characteristic String in Device Information Service.

**CONFIG\_SYSTEM\_WORKQUEUE\_STACK\_SIZE**

System work queue stack size.

**CONFIG\_SYSTEM\_WORKQUEUE\_PRIORITY**

System work queue priority.

**CONFIG\_BT\_HCI\_TRANSPORT\_INTERFACE\_TYPE**

HCI transport interface type.

**CONFIG\_BT\_HCI\_TRANSPORT\_INTERFACE\_INSTANCE**

HCI transport interface instance number.

**CONFIG\_BT\_HCI\_TRANSPORT\_INTERFACE\_SPEED**

HCI transport interface rate. Configures the interface speed, for example, the default interface is h4, the speed to 115200

**CONFIG\_BT\_HCI\_TRANSPORT\_TX\_THREAD**

Whether enable HCI transport TX thread.

**CONFIG\_BT\_HCI\_TRANSPORT\_RX\_THREAD**

Whether enable HCI transport RX thread.

**CONFIG\_BT\_HCI\_TRANSPORT\_RX\_STACK\_SIZE**

HCI transport RX thread stack size.

**CONFIG\_BT\_HCI\_TRANSPORT\_TX\_STACK\_SIZE**

HCI transport TX thread stack size.

**CONFIG\_BT\_HCI\_TRANSPORT\_TX\_PRIO**

HCI transport TX thread priority.

**CONFIG\_BT\_HCI\_TRANSPORT\_RX\_PRIO**

HCI transport RX thread priority.

**CONFIG\_BT\_MSG\_QUEUE\_COUNT**

Message number in message queue.

