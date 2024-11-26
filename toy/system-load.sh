#!/usr/bin/env bash

while true; do
    cpu_load="$(cat /proc/loadavg | cut -d " " -f 1-3)"
    mem_total_gb="$(awk '/MemTotal/ { printf "%.1f\n", $2/1024/1024 }' /proc/meminfo)"
    mem_available_gb="$(awk '/MemAvailable/ { printf "%.1f\n", $2/1024/1024 }' /proc/meminfo)"

    ./vrchat-osc chatbox \
        "CPU: ${cpu_load}" \
        "Memory: ${mem_available_gb}/${mem_total_gb}GiB"

    sleep 2
done
