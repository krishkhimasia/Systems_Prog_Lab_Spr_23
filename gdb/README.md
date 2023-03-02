

Q1)?

a) `list FUNCTION`

b) `set listsize SIZE`

c) ???

Q2) 

To compile and generate final executable file a.out with debugging enabled and run the same:
```bash
gcc -g allparts.c
gdb ./a.out
```
The list directive lists the first few (10 by default) lines of allparts.c

To list individual part files:
```gdb
list partx.c:LINENUM
``` 
To set breakpoint at specified line number in the part files:
```gdb
break FILENAME:LINENUM
```

Q3)?

To generate the object files and compile allparts.c:
```bash
gcc -c part1.c
gcc -c part2.c
gcc -c part3.c
gcc -g allparts.c part1.o part2.o part3.o
```
The list directive lists the first few (10 by default) lines of allpart.c

???

???

Q4)?




Q5) 

```gdb
file FILENAME
```



Q6) 

To re-run program from the start:
```gdb
run
```
The breakpoints set earlier are preserved.
The value history is preserved, but the values of the variable sets in the earlier run are not.


Q7)

To print value history:
```gdb
show values
```
Use `show` to print variables or expressions without sending the printed value to the value history.

Q8)

Use `ignore` directive.

For example, to ignore breakpoint '4' for the next 10 times: 
```gdb
ignore 4 10
```

Q9)

Set a breakpoint at a line in the program where you want to create the new variable. For example, you can set a breakpoint at line 10:
```gdb
break 10
```
When the program stops at the breakpoint, you can create a new variable using the `set` command. For example, you can create a new integer variable named var and set it to 69:
```gdb
set $var = 69
```
You can then use the new variable in GDB commands just like any other variable. For example, to print the value of var:
```gdb
print $my_var
```
If you want to delete the variable, you can use the `unset` command:
```gdb
unset $my_var
```
