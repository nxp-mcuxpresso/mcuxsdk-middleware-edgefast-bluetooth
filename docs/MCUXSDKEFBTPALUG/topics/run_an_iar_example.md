# Run an IAR example

This document uses the peripheral\_ht as an example to describe the steps to run an example. For details on other projects and compilers, see the readme file in the corresponding example directory.

The following figure shows the connection of RT1060 and the uSD wireless module.

![](../images/image9.png "Development board
				connector")

1.  Connect the USB debug console port to PC. For example, connect J14 of EVKRT1060 to the PC.
2.  Connect a 5 V power source to the J1 jack in the Wireless module board.
3.  Make the appropriate debugger settings in the project options window, as shown in the figure below.

    ![](../images/image10.png "IAR debugger CMSIS-DAP
    						selector")

4.  Click the **Download and Debug** button to flash the executable onto the board, as shown in the following figure. After the download is complete, if you must test the function of HFP, stop IAR debugging, and then connect the PCM interface. Reset the target board by manually.

    ![](../images/image11.png "IAR debugger
    						running")

5.  Linker layer \(LL\) Firmware running in wireless module loads from EVKRT1060 by SDIO interface, so need take a bit time to download the LL firmware, “Initialize AW-AM457-uSD Driver” prints in the debug console. For example, it depends on the firmware. For details, see readme.txt.

**Note:** The projects are configured to use “CMSIS DAP” as the default debugger. Ensure that the OpenSDA chip of the board contains a CMSIS. DAP firmware or that the debugger selection corresponds to the physical interface used to interface to the board.

**Parent topic:**[Run a demo application using IAR](../topics/run_a_demo_application_using_iar.md)

