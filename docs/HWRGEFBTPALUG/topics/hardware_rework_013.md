# Hardware rework

**HCI UART rework**

-   R398 move from 1-2 to 2-3
-   JP12 2-3
-   Connect the pins of two boards as the following table.

    |Pin Name|AW-AM457-uSD|i.MX RT685|PIN NAME|GPIONAME of i.MX RT685|
    |--------|------------|----------|--------|----------------------|
    |**UART\_TXD**|J10 \(pin 4\)|J27 \(pin 1\)|USART4\_RXD|FC4\_RXD\_SDA\_MOSI\_DATA|
    |**UART\_RXD**|J10 \(pin 2\)|J27 \(pin 2\)|USART4\_TXD|FC4\_TXD\_SCL\_MISO\_WS|
    |**UART\_RTS**|J10 \(pin 6\)|J47 \(pin 9\)|USART4\_CTS|FC4\_CTS\_SDA\_SSEL0|
    |**UART\_CTS**|J10 \(pin 8\)|J27 \(pin 5\)|USART4\_RTS|FC4\_RTS\_SCL\_SSEL1|
    |**GND**|J6 \(pin 7\)|J29 \(pin 6\)|GND|GND|

    ![](../images/457_1.jpg "MIMXRT685-EVK")

    ![](../images/image2_001.png "AW-AM457-uSD")


**Jumper Settings:**

-   Connect J4\[2-3\] for VIO 3.3 V supply
-   Connect J11\[2-3\] for VIO\_SD 3.3 V supply

**PCM interface rework**

Connect the pins of two boards as the following table.

|Pin Name|AW-AM457-uSD|i.MX RT685|PIN NAME of I.MX RT685|GPIONAME of I.MX RT685|
|--------|------------|----------|----------------------|----------------------|
|**PCM\_IN**|J9 \(pin 1\)|J47 \(pin 7\)|I2S2\_TXD|FC2\_RXD\_SDA\_MOSI\_DATA|
|**PCM\_OUT**|J9 \(pin 2\)|J28 \(pin 4\)|I2S5\_RXD|FC5\_RXD\_SDA\_MOSI\_DATA|
|**PCM\_SYNC**|J9 \(pin 3\)|J28 \(pin 5\)|I2S5\_WS|FC5\_TXD\_SCL\_MISO\_WS|
|**PCM\_CLK**|J9 \(pin 4\)|J28 \(pin 6\)|I2S5\_SCK|FC5\_SCK|
|**GND**|J9 \(pin 6\)|J29 \(pin 7\)|GND|GND|

**Parent topic:**[Hardware Rework Guide for MIMXRT685-EVK and AW-AM457-uSD](../topics/hardware_rework_guide_for_mimxrt685-evk_and_aw-am4.md)

