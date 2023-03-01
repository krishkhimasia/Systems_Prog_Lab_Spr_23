wSHELL = /bin/sh
CC = gcc

maxchain: libraries
	gcc maxchain.c -I../trie -I../util -L../trie -L../util -ltrie -lwordutils
	export LD_LIBRARY_PATH"=../trie:../util"; ./a.out

subwords: libraries
	gcc subwords.c -I../trie -I../util -L../trie -L../util -ltrie -lwordutils
	export LD_LIBRARY_PATH"=../trie:../util"; ./a.out

libraries:
	cd ..; make libraries