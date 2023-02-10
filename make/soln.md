

Q1)

Use the -n flag. It instructs make to print the commands that would be executed, but do not execute them (except  in
            certain circumstances).
```bash
make -n
```

Q2) 

Use the -B flag. It instructs make to unconditionally make all targets.
```bash
make -B
```

Q3)

First sees that a depends on b, and starts checking b's dependency list. Sees b depends on c, and
    starts checking c's dependency list. 
    
First it finds that c depends on a (which can't be made yet), hence drops c<-a dependency. Then it
    sees that c depends on b (which also can't be made yet), hencedrops c<-b dependency.
    
Now it makes c, goes back to checking the dependency list of b. Finds b depends on a (which can't
    be made yet), hence drops b<-a dependency and makes b.
    
Finally, it goes back to building a, and a is made.
    
```bash
$ make
make: Circular c <- a dependency dropped.
make: Circular c <- b dependency dropped.
Building c
make: Circular b <- a dependency dropped.
Building b
Building a
```

Q4) 

a) make doesnt proceed after it encounter in any error.
``` bash
$ make
/bin/sh: 1: ecko: not found
make: *** [makefile:4: b] Error 127
```

b) The -k flag instructs make to continue as much as possible after an error.  While the  target  that  failed,
            and those that depend on it, cannot be remade, the other dependencies of these
            targets can be processed all the same.
``` bash
$ make -k
/bin/sh: 1: ecko: not found
make: *** [makefile:4: b] Error 127
Building c
make: Target 'a' not remade because of errors.
```

c) The -i flag instructs make to ignore all errors in commands executed to remake files.
``` bash
$ make -i
/bin/sh: 1: ecko: not found
make: [makefile:4: b] Error 127 (ignored)
Building c
Building a
```



Q5) 

makefile1 uses *recursive assignment* operator (=), so value of A is also updated when B is updated to "Hello".
```bash
$ make -f makefile1
Hello
```

makefile 2 uses *evaluate once* assignment operator. A was assigned the value of B when B was empty, and value of A does not get updated when B is updated.
```bash
$ make -f makefile2


```

Q6) 

```make
A = $(B)
one: B = "abra"
one:
	@echo $(A) $(B)
two: B = "cadabra"
two:
	@echo $(A) $(B)
```

