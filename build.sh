#!/bin/bash

# sudo apt update -y
# sudo apt install build-essential g++ gdb netpbm


BINARY_FILE="./a.out"
# BINARY_FILE="./bin/a.out"
PPM_FILE="./images/out.ppm"
PNG_FILE="./images/out.png"


echo -e "\n==> Compiling binary"
g++ ./src/main.cpp -o $BINARY_FILE


if [[ -f $BINARY_FILE ]]; then
    echo -e "\n==> Executing binary"
    $BINARY_FILE
fi


if [[ -f $PPM_FILE ]]; then
    echo -e "\n==> Converting PPM image to PNG"
    pnmtopng $PPM_FILE > $PNG_FILE
fi


echo
