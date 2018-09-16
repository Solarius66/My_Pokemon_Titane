#!/bin/sh
sudo cd .
sudo dnf install xboxdrv
sudo dnf install joystick
sudo dnf install kernel-modules-extra
echo unplug and plug the joystick to the computer, then press enter
read s
jstest --event /dev/input/js0
