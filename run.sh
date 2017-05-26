#!/bin/bash

set -e

input_version="$1"
# use the naive version if nothing is passed in
version=${input_version:-NAIVE}

set -u

rm a.out

clang++ -std=c++14 -D"$version" -DCOMPARE -O3 \
    -Wextra -Wall -Weverything -pedantic \
    -Wno-c++98-compat -Wno-missing-prototypes \
    main.cpp

for file in ./inputs/input*.txt; do
    time ./a.out < "${file}";
    echo
done
