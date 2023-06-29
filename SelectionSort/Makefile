.DEFAULT_GOAL := all

selectionsort_hs: selectionsort.hs
	ghc selectionsort.hs -o selectionsort_hs

selectionsort_c: selectionsort.c
	gcc selectionsort.c -o selectionsort_c

all: selectionsort_hs selectionsort_c

clean:
	rm -f selectionsort_hs selectionsort.o selectionsort.hi selectionsort_c input.txt result.csv
