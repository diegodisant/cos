#!/bin/bash

source "./env.sh"

clang ${SOURCE_DIR}/bootloader/bootloader.s -o ${BUILDS_DIR}/bootloader.o
