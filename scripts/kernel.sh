#!/bin/bash

source "./env.sh"

clang ${SOURCE_DIR}/kernel/kernel.c \
  -fuse-ld=lld \
  -rtlib=compiler-rt \
  -o ${BUILDS_DIR}/kernel.o
