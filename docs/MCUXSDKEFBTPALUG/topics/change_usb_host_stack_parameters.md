# Change USB Host stack parameters

Since the board supports multiple USB ports, the demo provides a configurable interface for USB Host stack. The function*USB\_HostGetConfiguration* received the instance of USB for EdgeFast BT PAL. For the case where there is a USBPHY, the demo configures the properties of the PHY through*USB\_HostPhyGetConfiguration*.

**Note:** There are series of hex bytes printed on the console after the wireless module resets. However, it does not impact the EdgeFast BT PAL application running.

**Parent topic:**[Change board-specific parameters](../topics/change_board-specific_parameters.md)

