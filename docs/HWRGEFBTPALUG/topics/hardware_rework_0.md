# Hardware rework 
-   Murata uSD-M.2 jumper settings
    -   J12 = 1-2: WLAN-SDIO & BT-PCM = 1.8 V
    -   J13 = 1-2: BT-UART & WLAN/BT-CTRL = 3.3 V
    -   J1 = 2-3: 3.3 V from uSD connector
-   HCI UART interface rework

    Connect the TX/RX/RTS/CTS pins of the two boards as show in Table 1 using the jumper cables included in the Murata’s uSD-M.2 Adapter kit as shown in the following table.

    |Pin name|uSD-M.2 adapter pin|i.MX RT1050-EVKB pin|Pin name of RT1050-EVKB|GPIO name of RT1050-EVKB|
    |--------|-------------------|--------------------|-----------------------|------------------------|
    |BT\_UART\_TXD\_HOST|J9 \(pin 1\)|J22 \(pin 1\)|LPUART3\_RXD|GPIO\_AD\_B1\_07|
    |BT\_UART\_RXD\_HOST|J9 \(pin 2\)|J22 \(pin 2\)|LPUART3\_TXD|GPIO\_AD\_B1\_06|
    |BT\_UART\_RTS\_HOST|J8 \(pin 3\)|J23 \(pin 3\)|LPUART3\_CTS|GPIO\_AD\_B1\_04|
    |BT\_UART\_CTS\_HOST|J8 \(pin 4\)|J23 \(pin 4\)|LPUART3\_RTS|GPIO\_AD\_B1\_05|
    |GND|J7 \(pin 7\)|J25 \(pin 7\)|GND|GND|


**Parent topic:**[Hardware Rework Guide for IMXRT1050-EVKB and Murata M.2 Module](../topics/hardware_rework_guide_for_imxrt1050_evkb_and_murata_m_2_module.md)

