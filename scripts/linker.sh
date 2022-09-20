#!/bin/bash

source "./env.sh"

clang -T ${SOURCE_DIR}/bootloader/linker.ld \
  -o ${BUILDS_DIR}/cos.bin \
  -ffreestanding \
  -O2 \
  -nostdlib \ #@TODO check if this can be removed
  ${BUILDS_DIR}/bootloader.o ${BUILDS_DIR}/kernel.o
