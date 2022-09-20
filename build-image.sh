#!/bin/bash

docker build \
  -t diegodisant/cos:latest \
  --network host . #@TODO change to host when implements network features

