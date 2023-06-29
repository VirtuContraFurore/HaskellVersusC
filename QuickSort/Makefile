.DEFAULT_GOAL := all

quicksort_hs: quicksort.hs
	ghc quicksort.hs -o quicksort_hs

quicksort_c: quicksort.c
	gcc quicksort.c -o quicksort_c

all: quicksort_hs quicksort_c

clean:
	rm -f quicksort_hs quicksort.o quicksort.hi quicksort_c input.txt result.csv
