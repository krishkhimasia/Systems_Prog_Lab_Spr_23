

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


Q10)

```gdb
# setting breakpoint 1 at line 234
break 234
condtion 1 p==NULL

# to find n
print n
```


Q11) binary search?


Q12)

To set a watchpoint which pauses execution when x changes its value:
```gdb
# to set watchpoint for a variable x
watch x

# when the variable changes its value
Hardware watchpoint N: x

Old value = ...
New value = ...
```
We can list, enable/disable & delete watchpoints as follows:
```gdb
# to list all the watchpoints
info watchpoints

# disable/enable/delete watchpoint
disable watchpoint N
enable watchpoint N
delete watchpoint N
```
We can also set conditional watchpoints. The following example would pause execution when x exceeds 69:
```gdb
# conditional watchpoints
watch x if x>69
```

Q13)

The 'x' command is used to examine memory.

The syntax is : `x /[format] [length] [address]` , where:

- **format** specifies the display format for the memory contents (such as x for hexadecimal, d for decimal, or c for character)

- **length** specifies the number of units to display

- **address** is the memory address to examine.

For example, `x /x 16 0x1000` will examine 16 bytes of memory starting at address 0x1000 in hexadecimal format.
```gdb
# to examine contents of an integer variable var
x /d &var

# other examples
x /t 0x1000  # display a byte at address 0x1000
x /h 0x1000  # display a half-word at address 0x1000
x /w 0x1000  # display a word at address 0x1000
x /i 0x1000  # display the disassembled instruction at address 0x1000
x /s 0x1000  # display a null-terminated string at address 0x1000
```


Q14)
```gdb
# display 5 words (4 bytes each) starting at the memory address A in hexadecimal format
x /5wx A
0x7fffffffdc90: 0x0000000f      0x00000010      0x00000011      0x00000000
0x7fffffffdca0: 0x00000000

# displays the 5 words (4 bytes each) starting at the memory address (A+1) in hexadecimal format
x /5wx A+1
0x7fffffffdc94: 0x00000010      0x00000011      0x00000000      0x00000000
0x7fffffffdca4: 0x00000000

# displays the 5 words (4 bytes each) starting at the memory address (A-1) in hexadecimal format
x /5wx A-1
0x7fffffffdc8c: 0x00000000      0x0000000f      0x00000010      0x00000011
0x7fffffffdc9c: 0x00000000

# displays contents of i in hexadecimal format, 0 or garbage value in this case as  is uninitialised
x /1wx &i
0x7fffffffdc8c: 0x00000000
```


Q15)

We set a breakpoint using the command `break g`. The execution pauses at line 100 (as it makes the first call of g()) and we can use the next command to scrutinize g() line by line. After this we can disable the breakpoint so it does not interrupt the program execution when g() is encountered again.


Q16)

We can set a breakpoint at line 100, and let the program run until it hits our breakpoint. At our breakpoint, we can use the `step` command to step into either f() or g().
- If we step into g(), we can examine its working line by line using the `next` command.
- If we step into f(), we can use `finish` command to skip examining f() and then using `step` command to step into g().


Q17)

We can set a breakpoint at line 64, and let the program run until it hits our breakpoint. At our breakpoint, we use the `step` command to step into the inner f(), use `finish` command to skip line by line examination of f(), and then use the `next` command to scrutinize the working of g() line by line.


Q18)

You can set a breakpoint at Line 128 and then use gdb's `if` command to check if the value of t is non-zero before continuing execution. If **t** is *non-zero*, you can use the continue command to resume normal execution. If **t** is *zero*, you can use the `return` command to exit the current function and return to the caller (main() in this case).

- Set breakpoint using `break myfunc:128`
- When program stops at breakpoint, write this:     
```gdb
if t != 0 then continue else return end
```


Q19)?
