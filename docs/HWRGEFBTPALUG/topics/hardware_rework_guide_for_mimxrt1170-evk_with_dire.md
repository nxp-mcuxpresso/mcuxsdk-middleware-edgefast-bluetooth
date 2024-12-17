# Hardware Rework Guide for MIMXRT1170-EVK and Murata M.2 Module

This section is a brief hardware rework guidance of the Edgefast Bluetooth PAL on the NXP i.MX MIMXRT1170-EVK board and the Murata 1XK or 1ZM solution - direct M.2 connection to Embedded Artists’ EAR00385 \(1XK\) or EAR00364 \(1ZM\) M.2 modules. The rework is necessary to connect the RADIO\_ENABLE \(or WL\_RTS\) signal in addition to two UART signals.

The hardware rework consists of two parts:

-   HCI UART rework
-   Radio control signal rework \(RADIO\_ENABLE\)


```{include} ../topics/hardware_rework_011.md
:heading-offset: 1
```

