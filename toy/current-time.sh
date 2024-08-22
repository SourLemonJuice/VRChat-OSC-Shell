#!/usr/bin/env bash

while true; do
    ./vrchat-osc chatbox "$(date --iso-8601=seconds)" || exit 1
    sleep 2
done
