#!/bin/bash

rm -rf results
mkdir results

for test in $(ls -d */); do
    pushd $test
    make all
    ./test.sh
    cp ./result.csv ../results/${test::-1}.csv
    make clean
    popd
done
