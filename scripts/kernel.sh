#!/bin/bash

source "./env.sh"

clang ${SOURCE_DIR}/kernel/kernel.c -o ${BUILDS_DIR}/kernel.o
