#!/bin/bash

# sudo apt update -y
# sudo apt install build-essential netpbm


### Vars
BINARY_FILE="./out"
PPM_FILE="./images/out.ppm"
PNG_FILE="./images/out.png"


### Compile
echo -e "\n==> $ g++ main.cpp -o $BINARY_FILE"
g++ main.cpp -o $BINARY_FILE


### Run
if [[ -f $BINARY_FILE ]]; then
    echo -e "\n==> $ $BINARY_FILE"
    $BINARY_FILE
fi


### Convert PPM --> PNG
if [[ -f $PPM_FILE ]]; then
    echo -e "\n==> $ pnmtopng $PPM_FILE > $PNG_FILE"
    pnmtopng $PPM_FILE > $PNG_FILE
fi


echo
