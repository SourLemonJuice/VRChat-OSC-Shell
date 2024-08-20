#!/usr/bin/env bash

# 在 chatbox 里显示距离黑神话悟空还有多久结束预下载
# 一个小玩具

target_string="2024-08-20 10:00"

while true; do
    today=$(($(date +%s) / 60))
    target=$(($(date --date "${target_string}" +%s) / 60))
    minutes=$(($target - $today))
    ./main.out "距离 ${target_string} 还有 ${minutes} 分钟" || exit 1
    sleep 10
done
