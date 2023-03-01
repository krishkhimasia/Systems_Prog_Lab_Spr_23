SHELL = /bin/sh
CC = gcc

library: trie.o
	gcc -shared -o libtrie.so trie.o

trie.o: trie.h
	gcc -Wall -fPIC -I. -c trie.c
