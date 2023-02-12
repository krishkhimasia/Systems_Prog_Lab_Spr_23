Q1)

	gcc -Wall -c common.c foo.c bar.c
	
	ar rcs libnumprn.a common.o foo.o bar.o

Q2)

	gcc -Wall -L. app.c -lnumprn (for uninteractive mode)

	gcc -Wall -L. -DINTERACTIVE app.c -lnumprn (for interactive mode)

	./.a.out

Q3)

	gcc -Wall -fPIC -c common.c foo.c bar.c

	gcc -shared -o libnumprn.so common.o foo.o bar.o

Q4)

	export LD_LIBRARY_PATH=.

	gcc -Wall -L. app.c -lnumprn (for uninteractive mode)

	gcc -Wall -L. -DINTERACTIVE app.c -lnumprn (for interactive mode)

	./a.out
