SHELL = /bin/sh
CC = gcc

libraries:		#to build libraries
	cd trie; make
	cd util; make

maxchain:	#to compile/run maxchain.c

	cd apps; make maxchain

subwords:	#to compile/run subwords.c
	cd apps; make subwords

clean:			#deletes object files
	cd trie; rm -f trie.o
	cd util; rm -f dictload.o dictutils.o

distclean:		#deletes object files, libraries, and the executables
	cd trie; rm -f trie.o libtrie.so
	cd util; rm -f dictload.o dictutils.o libwordutils.so
	cd apps; rm -f a.out

