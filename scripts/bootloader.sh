#!/bin/bash

source "./env.sh"

clang ${SOURCE_DIR}/bootloader/bootloader.s \
-fuse-ld=lld \
-rtlib=compiler-rt \
-o ${BUILDS_DIR}/bootloader.o
