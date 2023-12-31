#!/bin/bash

make
clear
echo -e "MAP:\n\n$(cat map)\n"
./setting_up map
make fclean >/dev/null
