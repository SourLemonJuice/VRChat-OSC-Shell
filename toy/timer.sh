#!/usr/bin/env bash

# Send a simple timer to the chatbox

start_time=$(date +%s)
while true; do
    now=$(($(date +%s) - start_time))
    # Thanks for:
    # https://stackoverflow.com/a/39452629/25416550
    ./vrchat-osc chatbox "Timer: $(printf '%02d:%02d:%02d\n' $((now / 3600)) $(( now % 3600 / 60 )) $(( now % 60 )))"
    sleep 1
done
