#!/usr/bin/env bash

# Simulate a external chatbox in the shell, for some reason
# This script depends on shell-readline
# https://github.com/SourLemonJuice/Shell-readline

./vrchat-osc typing on
echo "Input message on the next line:"
./vrchat-osc chatbox "$(shell-readline)"
./vrchat-osc typing off
