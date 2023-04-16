#!/bin/bash

### Prep
# sudo apt update -y
# sudo apt install build-essential netpbm


### Vars
BINARY_FILE="./out"
PPM_FILE="./images/out.ppm"
PNG_FILE="./images/out.png"


# ### Delete old binary
# if [[ -f $BINARY_FILE ]]; then
#     echo -e "\n==> $ rm $BINARY_FILE"
#     rm $BINARY_FILE
# fi


# ### Delete old images
# if [[ -f $PPM_FILE ]]; then
#     echo -e "\n==> $ rm ./images/*.p*"
#     rm ./images/*.p*
# fi


### Compile
echo -e "\n==> $ g++ main.cpp -o $BINARY_FILE"
g++ main.cpp -o $BINARY_FILE


### Run new binary
if [[ -f $BINARY_FILE ]]; then
    echo -e "\n==> $ $BINARY_FILE"
    $BINARY_FILE
fi


### Convert PPM file to PNG
if [[ -f $PPM_FILE ]]; then
    echo -e "\n==> $ pnmtopng $PPM_FILE > $PNG_FILE"
    pnmtopng $PPM_FILE > $PNG_FILE
fi


echo
