#!/bin/bash

make || exit
./setting_up tests/demo
make fclean >/dev/null
