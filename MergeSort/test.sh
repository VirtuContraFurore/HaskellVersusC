#!/bin/bash

rm -f ./result.csv
echo "Array lenght, Haskell [s], C [s]" >> ./result.csv

for list_len in 1000 10000 100000 1000000; do
    for i in {1..10}; do
        # Clear list if existing
        rm -f ./input.txt

        # Generate some random numbers
        python3 ./rand.py $list_len "./input.txt"

        exec 3>&1 4>&2
        time_hs=$( TIMEFORMAT="%R"; { time ./mergesort_hs 1>&3 2>&4; } 2>&1)
        exec 3>&- 4>&-

        exec 3>&1 4>&2
        time_c=$( TIMEFORMAT="%R"; { time ./mergesort_c 1>&3 2>&4; } 2>&1)
        exec 3>&- 4>&-

        echo "$list_len, $time_hs, $time_c" >> ./result.csv
    done
done

