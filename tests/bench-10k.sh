#!/bin/bash

mkdir -p 10k

for i in {0..10..1}; do
    echo perl gen.pl 10000 10000 "$i"
    [ -f "10k/10k-$i" ] || \
    perl gen.pl 10000 10000 "$i" > "10k/10k-$i"
done
for i in {10..100..10}; do
    echo perl gen.pl 10000 10000 "$i"
    [ -f "10k/10k-$i" ] || \
    perl gen.pl 10000 10000 "$i" > "10k/10k-$i"
done
for i in {100..1000..100}; do
    echo perl gen.pl 10000 10000 "$i"
    [ -f "10k/10k-$i" ] || \
    perl gen.pl 10000 10000 "$i" > "10k/10k-$i"
done
for i in {1000..10001..1000}; do
    echo perl gen.pl 10000 10000 "$i"
    [ -f "10k/10k-$i" ] || \
    perl gen.pl 10000 10000 "$i" > "10k/10k-$i"
done

cd ..
echo
make fast || exit
echo

for i in $(ls -1 tests/10k/* | sort -t '-' -k 2 -nr); do
    echo -n "Testing ${i##*/}... "
    start=$(date +%s.%N)
    ./setting_up "$i" >/dev/null
    end=$(date +%s.%N)
    printf "%.2fs\n" $(echo "$end - $start" | bc)
done
