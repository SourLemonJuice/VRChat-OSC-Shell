#!/usr/bin/env bash

while true; do
    ./main.out "$(date --iso-8601=seconds)" || exit 1
    sleep 2
done
