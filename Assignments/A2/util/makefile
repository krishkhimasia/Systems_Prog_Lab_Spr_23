SHELL = /bin/sh
CC = gcc

library: dictload.o dictutils.o
	gcc -shared -L../trie -o libwordutils.so dictload.o dictutils.o -ltrie

dictload.o: dictload.h dicttype.h
	gcc -Wall -L. -L../trie -fPIC -I. -I../trie -c dictload.c -ltrie

dictutils.o: dictutils.h dicttype.h
	gcc -Wall -L. -L../trie -fPIC -I. -I../trie -c dictutils.c -ltrie