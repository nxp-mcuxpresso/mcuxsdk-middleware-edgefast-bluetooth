# Hardware rework

1.  **HCI UART rework:**

    On MIMXRT1170-EVK board, populate R1901 and R1902 with zero Ohm resistors. This connects the BT\_UART\_RXD and BT\_UART\_CTS signals respectively to the M.2 connector.

2.  **Radio control signal rework \(WL\_CTS\):**

    On MIMXRT1170-EVK board, populate R404 with a zero Ohm resistor. Remove R183 resistor. This connects the WL\_RST signal directly to the M.2 connector. This signal resets both wireless cores.


**Parent topic:**[Hardware Rework Guide for MIMXRT1170-EVK and Murata M.2 Module](../topics/hardware_rework_guide_for_mimxrt1170-evk_with_dire.md)

