#!/bin/bash

mkdir -p gen

for i in {1..10}; do
    for j in {1..10}; do
        perl gen.pl "$i" "$j" 3 > "gen/$i-$j"
    done
done
