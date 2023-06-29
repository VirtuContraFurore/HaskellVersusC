#!/bin/bash

# Lenght of input list
INPUT_LIST_LEN=500000

rm -f ./result.csv
echo "Haskell, C" >> ./result.csv

for i in {1..10}; do

    # Clear list if existing
    rm -f ./input.txt

    # Generate some random numbers
    python3 ./rand.py $INPUT_LIST_LEN "./input.txt"

    exec 3>&1 4>&2
    time_hs=$( TIMEFORMAT="%R"; { time ./quicksort_hs 1>&3 2>&4; } 2>&1)
    exec 3>&- 4>&-

    exec 3>&1 4>&2
    time_c=$( TIMEFORMAT="%R"; { time ./quicksort_c 1>&3 2>&4; } 2>&1)
    exec 3>&- 4>&-

    echo "$time_hs, $time_c" >> ./result.csv

done

