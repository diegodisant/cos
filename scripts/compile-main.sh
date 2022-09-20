#!/bin/bash

# compile the entry point in order to test the code

source "./env.sh"

clang ${SOURCE_DIR}/display/vga.c \
  ${SOURCE_DIR}/logger/log.c \
  ${SOURCE_DIR}/shell/shell.c \
  ${SOURCE_DIR}/main.c \
  -std=c17 \
  -target aarch64-apple-darwin \
  -o ${SOURCE_DIR}/main.o
