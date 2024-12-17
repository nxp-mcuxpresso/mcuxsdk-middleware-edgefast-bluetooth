# Build an IAR example

1.  Select `flexspi_nor_debug` or `flexspi_nor_release` configurations from the drop-down selector above the project tree in the workspace.

    ![](../images/image7.png "IAR Project target
    							switch")

2.  Build the EdgeFast Bluetooth Protocol Abstraction Layer project.

    ![](../images/image8.png "IAR project
    							build")

    **Note:** Wireless module does not have flash hardware and requires 512 KB image loaded from board \(such as RT1060\) on system startup. The 512 KB image is kept on RT1060 side and only `flexspi_nor target` is supported for Bluetooth examples. Other targets are not supported because memory size limit.


**Parent topic:**[Run a demo application using IAR](../topics/run_a_demo_application_using_iar.md)

