
Until we get a repo manifest repository going this is the steps to get this code going:

```
mkdir camkes-project
cd camkes-project
repo init -u https://github.com/seL4/camkes-manifest.git
repo sync
```

Clone this repository in the apps folder of the camkes-project directory. Rename the app folder:

```
mv apps/camkes-temp-system apps/temp_system
```


Add a source line to the top-level Kconfig under the applications menu that references this file:

```
source "apps/temp_system/Kconfig"
```

Run the following commands to make a configuration:

```
make menuconfig
```

Goto applications and select the temp controller, deselect the simple application under examples.
Save your new configuration.

```
cp .config configs/arm_temp_system_defconfig
make
qemu-system-arm -M kzm -nographic -kernel images/capdl-loader-experimental-image-arm-imx31
```


CAmkES Documentation:
https://github.com/seL4/camkes-tool/blob/master/docs/index.md
http://sel4.systems/Info/CAmkES/GettingStarted.pml
http://sel4.systems/Info/CAmkES/Tutorial.pml
