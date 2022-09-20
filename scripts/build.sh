#!/bin/bash

source "./env.sh"

echo "COS Builder"
echo "[+] Deleting old build files..."

rm -rfv ${BUILDS_DIR}/*.o
rm -rfv ${BUILDS_DIR}/*.bin

echo "[+] Building Bootloader..."

./bootloader.sh

echo "[+] Building OS Kernel..."

./kernel.sh

echo "[+] Building Linker with the Kernel and Bootloader..."

./linker.sh
