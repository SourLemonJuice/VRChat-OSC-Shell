#!/usr/bin/env bash

# This script depends on:
# Shell-readline
# https://github.com/SourLemonJuice/Shell-readline
# Translate Shell
# https://github.com/soimort/translate-shell

trans_target_code="en"

./vrchat-osc typing on

echo "Input message on the next line:"
input_content="$(shell-readline)"
translate_content=$(echo "$input_content" | trans -brief --target "$trans_target_code")
./vrchat-osc chatbox "${input_content} |-> ${trans_target_code}| ${translate_content}"

./vrchat-osc typing off
