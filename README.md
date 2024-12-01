# ZMK Config

## Corne

![keymap](config/corne.svg)


## To flash

Connect the keyboard to the machine using a standard usb cable.
Press the `reset` button twice in short succession.
At this point the OS should ask if you want to allow the USB accessorie to connect, or if you already did it in the past it will just show up as another volume.

On OSX it will show up under `/Volumes/NICENANO`.

To flash the firmware simply move the respective `.uf2` file to the volume.

```shell
mv corne_left-nice_nano_v2-zmk.uf2 /Volumes/NICENANO
```

## To build

Easiest way to build is via the `.devcontainer` setup.

Build the devcontainer by running `devcontainer up` or by opening the project in vscode.
To build the firmware for flashing run this command:

```shell
cd /zmk
export FW_FILE=/workspaces/zmk-config/build/corne_left-zmk.uf2
rm -rf build && west build -s app -d build -b nice_nano_v2 -- -DZMK_CONFIG=$WORKPACE_PATH/config -DSHIELD="corne_left nice_view_adapter nice_view_gem" -DZMK_EXTRA_MODULES="/workspaces/zmk-config/" && cp build/zephyr/zmk.uf2 $FW_FILE
```

Then flash from the host machine using `mv build/corne_left-zmk.uf2 /Volumes/NICENANO`
