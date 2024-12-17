# Change HCI UART parameters

Since the controller can support different baud rates, the demo provides an interface with configurable baud rates. The function*controller\_hci\_uart\_get\_configuration* is used to get HCI UART parameters, including the instance, default baud rate, which depends on the controller, running baud rate which defined by macro BOARD\_BT\_UART\_BAUDRATE and so on. If this function returns '0' and the running baud rate is inconsistent with the default baud rate, EdgeFast BT PAL switches the baud rate of the controller to the running baud rate.

**Parent topic:**[Change board-specific parameters](../topics/change_board-specific_parameters.md)

