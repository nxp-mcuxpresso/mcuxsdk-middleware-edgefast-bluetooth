# Common steps

1.  Download `SDK_2.14.0_EVKC-MIMXRT1060` and `SDK_2.14.0_EVK-MIMXRT1064`.
2.  Copy the following folders from the `RT1060EVKC` package to the `RT1064` package: `<install_dir>/middleware/edgefast_bluetooth/ <install_dir>/middleware/wireless/ethermind`.
3.  Create a new folder named `edgefast_bluetooth_examples/ under <rt1064_install_dir>/boards/evkmimxrt1064/`.
4.  Copy the entire folder from `<rt1060evkc_install_dir>/boards/evkcmimxrt1060/edgefast_bluetooth_examples/peripheral_ht/` to `<rt1064_install_dir>/boards/evkmimxrt1064/edgefast_bluetooth_examples/`.
5.  Copy `clock_config.[c/h]` and `board.c` from `<rt1064_install_dir>/boards/evkmimxrt1064/demo_apps/hello_world/` to `<rt1064_installed>/boards/evkmimxrt1064/edgefast_bluetooth_examples/peripheral_ht/` to replace the previous files.

**Parent topic:**[Migrate examples from RT1060EVKC to RT1064](../topics/migrate_examples_from_rt1060evkc_to_rt1064.md)

