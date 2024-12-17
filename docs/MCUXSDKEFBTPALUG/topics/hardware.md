# Hardware

For dual-chip implementation, the Bluetooth demo runs on a \(reference board\) along with the ported EdgeFast Bluetooth Protocol Abstraction Layer API host stack. The Linker Layer \(LL\) runs on a wireless module. A standard UART HCI and PCM is used to communicate between the two boards, the IMU is used to communicate in between. The Bluetooth host and controller stack run on different boards. The demo hardware requires two different boards; a development board for host stack and application and a wireless module adapter board for controller running. For example, the evkmimxrt1060 and uSD-15x15 Adapter Board for AW-AM457-uSD board, or any of the supported Murata modules with the Murata uSD-M.2 adapter. For details on the board hardware requirement and board setting, see the following documents. For one-chip implementation, the Bluetooth demo, EdgeFast Bluetooth Protocol Abstraction Layer API host stack, and LL run on one chip and they communicate with IMU.

-   Hardware rework guide document of the relative board, Hardware Rework Guide for MIMXRT1060-EVK and AW-AM457-uSD, or Hardware Interconnection Guide for i.MX RT EVKs and Murata M.2 modules.
-   Readme file of the examples.


```{include} ../topics/reference_boards_list.md
:heading-offset: 1
```

```{include} ../topics/dual-chip_wireless_module_list.md
:heading-offset: 1
```

