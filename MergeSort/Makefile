.DEFAULT_GOAL := all

mergesort_hs: mergesort.hs
	ghc mergesort.hs -o mergesort_hs

mergesort_c: mergesort.c
	gcc mergesort.c -o mergesort_c

all: mergesort_hs mergesort_c

clean:
	rm -f mergesort_hs mergesort.o mergesort.hi mergesort_c input.txt result.csv
