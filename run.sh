#!/bin/bash

clang++ -std=c++14 main.cpp

for file in ./inputs/input*.txt; do
    ./a.out < "${file}";
    echo
done
