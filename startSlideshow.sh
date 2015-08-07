#!/bin/sh
xset -dpms
xset s off
xset s noblank
sudo nodejs /home/pi/raspi-slideshow/server.js &
matchbox-window-manager &
epiphany http://localhost:81
