.DEFAULT_GOAL := all

binarysearch_hs: binarysearch.hs
	ghc binarysearch.hs -o binarysearch_hs

binarysearch_c: binarysearch.c
	gcc binarysearch.c -o binarysearch_c

all: binarysearch_hs binarysearch_c

clean:
	rm -f binarysearch_hs binarysearch.o binarysearch.hi binarysearch_c input.txt result.csv
