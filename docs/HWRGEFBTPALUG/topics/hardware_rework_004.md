# Hardware rework

-   **HCI UART rework**
    1.  Remove R293 and R354, connect R293 pin2 with R354 Pin1.
    2.  Remove R241 and R163, connect R93 pin1 with R241 Pin2.
    3.  Solder R96, R93, R87, R79, R70, and R345.
    4.  Remove R193.

        ![](../images/image1jpeg.jpg "MIMXRT1060-EVKB (Back)")

        ![](../images/image2jpeg_001.jpg "MIMXRT1060-EVKB (Front)")

-   **I2S2 rework**
    1.  Open jumpers: J35, J36, J37, and J41.
    2.  Connect J35 \(Pin2\) with J19 \(Pin3\) and solder R341.
    3.  Connect J36 \(Pin2\) with J19 \(Pin9\) and solder R334
    4.  Connect J41 \(Pin2\) with TP11.
    5.  Connect J37 \(Pin2\) with J16 \(Pin5\).
    6.  Connect R428 with R254 \(Pin2\), remove R254, R173, and R175.
    7.  Remove R86, R76, and R381.

        ![](../images/image3jpeg.jpg "MIMXRT1060-EVKB (Front)")

        ![](../images/image4jpeg_001.jpg "MIMXRT1060-EVKB (Back)")

-   **M.2 SDIO rework**
    1.  Solder R368, R376, R347, R349, R365, and R363.
    2.  Remove R364, R366, R351, R348, R377, and R369.

        ![](../images/image5jpeg.jpg "MIMXRT1060-EVKB (Back)")


**Parent topic:**[Hardware Rework Guide for MIMXRT1060-EVKB and AW-AM510MA](../topics/hardware_rework_guide_for_mimxrt1060-evkb_and_aw-a.md)

