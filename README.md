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