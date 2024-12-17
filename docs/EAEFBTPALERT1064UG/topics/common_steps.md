# Common steps

1.  Download *SDK\_2.13.0\_EVK-MIMXRT1060* and *SDK\_2.13.0\_EVK-MIMXRT1064*.
2.  Copy the following folders from RT1060EVK package to RT1064 package: `<install_dir>/components/internal_flash/ <install_dir>/middleware/edgefast_bluetooth/ <install_dir>/middleware/wireless/`.
3.  Create a folder named `edgefast_bluetooth_examples/` under `<rt1064_install_dir>/boards/evkmimxrt1064/`.
4.  Copy the entire folder from `<rt1060evk_install_dir>/boards/evkmimxrt1060/edgefast_bluetooth_examples/peripheral_ht/` to `< rt1064_install_dir>/boards/evkmimxrt1064/edgefast_bluetooth_examples/`.
5.  Copy *clock\_config.\[c/h\]* and *board.c* from `<rt1064_install_dir>/boards/evkmimxrt1064/demo_apps/hello_world/` to `<rt1064_installed>/boards/evkmimxrt1064/edgefast_bluetooth_examples/peripheral_ht/` to replace the previous files.
6.  Add `#define EDGEFAST_BT_LITTLEFS_MFLASH 1` in `<rt1064_install_dir>/boards/ evkmimxrt1064/edgefast_bluetooth_examples/peripheral_ht /app_config.c`.
7.  Make the following changes in `<rt1064_installed>/boards/evkmimxrt1064/edgefast_bluetooth/peripheral_ht/board.h`.

    ![](../images/image1.png)


**Parent topic:**[Migrate examples from RT1060EVK to RT1064](../topics/migrate_examples_from_rt1060evk_to_rt1064.md)

