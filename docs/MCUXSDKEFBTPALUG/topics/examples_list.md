# Examples list

-   The following examples are provided. Not all the examples are implemented on all the boards. See the board package for a list of the implemented examples.
    -   **central\_hpc \(central http proxy service client\)**: Demonstrates a basic Bluetooth Low Energy Central role functionality. The application scans for other Bluetooth Low Energy devices and establishes a connection to the peripheral with the strongest signal. The application specifically looks for HPS Server and programs a set of characteristics that configures a Hyper Text Transfer Protocol \(HTTP\) request, initiates request, and reads the response once connected.
    -   **central\_ht \(central health thermometer\)**: Demonstrates a basic Bluetooth Low Energy Central role functionality. The application scans for other Bluetooth Low Energy devices and establishes a connection to the peripheral with the strongest signal. The application specifically looks for health thermometer sensor and reports the die temperature readings once connected.
    -   **central\_ipsp \(central Internet protocol support profile\)**: Demonstrates a basic Bluetooth Low Energy Central role functionality. The application scans for other Bluetooth Low Energy devices and establishes connection to the peripheral with the strongest signal. The application specifically looks for IPSP Service and communicates between the devices that support IPSP. Once connected, the communication is done using IPv6 packets over the Bluetooth Low Energy transport.
    -   **central\_pxm \(central proximity monitor\)**: Demonstrates a basic Bluetooth Low Energy Central role functionality. The application scans for other Bluetooth Low Energy devices and establishes a connection to the peripheral with the strongest signal. The application specifically looks for Proximity Reporter.
    -   **peripheral beacon**: Demonstrates the Bluetooth Low Energy Peripheral role, This application implements types of beacon applications.

        -   **beacon**: Demonstrates the Bluetooth Low Energy Broadcaster role functionality by advertising Company Identifier, Beacon Identifier, UUID, A, B, C, RSSI.

        -   **Eddystone**: The Eddystone Configuration Service runs as a GATT service on the beacon while it is connectable and allows configuration of the advertised data, the broadcast power levels, and the advertising intervals.

        -   **iBeacon**: Demonstrates the Bluetooth Low Energy Broadcaster role functionality by advertising an Apple iBeacon.

    -   **peripheral\_hps \(peripheral http proxy service\)**: Demonstrates the Bluetooth Low Energy Peripheral role. The application specifically exposes the HTTP Proxy GATT Service.
    -   **peripheral\_ht \(peripheral health thermometer\)**: Demonstrates the Bluetooth Low Energy Peripheral role. The application specifically exposes the HT \(Health Thermometer\) GATT Service. Once a device connects, it generates dummy temperature values.
    -   **peripheral\_ipsp \(peripheral Internet protocol support profile\)**: Demonstrates the Bluetooth Low Energy Peripheral role. The application specifically exposes the Internet Protocol Support GATT Service.
    -   **peripheral\_pxr \(peripheral proximity reporter\)**: Demonstrates the Bluetooth Low Energy Peripheral role. The application specifically exposes the Proximity Reporter \(including LLS, IAS, and TPS\) GATT Service.
    -   **wireless uart**: The application automatically starts advertising the wireless uart service and connects to the wireless uart service after the role switch. The wireless UART service is a custom service that implements a custom writable ASCII Char characteristic \(UUID: 01ff0101-ba5e-f4ee-5ca1-eb1e5e4b1ce0\) that holds the character written by the peer device.

    -   **spp \(serial prot profile\)**: Application demonstrates the use of the SPP feature.
    -   **handsfree**: Application demonstrating usage of the Hands-free Profile \(HFP\) feature.
    -   **handsfree\_ag**: Application demonstrating usage of the Hands-free Profile Audio Gateway \(HFP-AG\) feature.
    -   **a2dp\_sink**: Application demonstrating how to use the a2dp sink feature.
    -   **a2dp\_source**: Application demonstrating how to use the a2dp source feature.
    -   **audio\_profile**: Demonstrates the following functions.
        -   There are five parts working in the demo: AWS cloud, Android app, audio demo \(running on RT1060\), U-disk, and Bluetooth headset.

        -   With an app running on the smartphone \(Android phone\), the end user connects to the AWS cloud and controls the audio demo running on the RT1060 EVK board through AWS cloud. Some operations like play, play next, and pause are used to control the media play functionalities.

        -   Audio demo running on the RT1060 EVK board connects to the AWS through WiFi. A connection establishes between the RT1060 EVK board and a Bluetooth headset. To get the media resource \(mp3 files\) from the U-disk, an HS USB host is enabled, and a U-disk with mp3 files is connected to RT1060 EVK board via the USB port. The audio demo searches the root directory of the U-disk for the music files \(only mp3 files are supported\) and uploads the song file list to AWS. The song list is shown in the app running on the smartphone. The music can then be played out via the Bluetooth headset once end user controls the app to play the mp3 file.

    -   **wifi\_provisioning**: Demonstrates the WiFi provisioning service that safely sends credential from phone to device over Bluetooth low energy. By default, AWS Wi-Fi provisioning demo starts advertising if the Wi-Fi access point \(AP\) is not configured and waits for the Wi-Fi AP configuration. After connecting to the Android APK, the demo executes the request from cellphone and sends the response. When the Wi-Fi AP is configured, the Shadow demo connects to the AWS via Wi-Fi and publishes the configured Wi-Fi AP information.

    -   **shell**: Shell application demonstrating the shell mode of the simplified Adapter APIs.


**Parent topic:**[Overview](../topics/overview.md)

