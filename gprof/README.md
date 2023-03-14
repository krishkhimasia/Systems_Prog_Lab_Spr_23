
Q1)

```bash
# create first profile-data file gmon.out
./secretapp

# rename it to gmon.sum
mv gmon.out gmon.sum

# Merge the new data in gmon.out into gmon.sum using -s flag, repeat this 9 more times
gprof -s executable-file gmon.out gmon.sum
```

Q2)

For N=100000,
```bash
# compile
gcc -pg prog.c -lm

# run and create profile-data file
./a.out

# open gmon.out
gprof ./a.out gmon.out
```

gmon.out displays the following:
```gprof
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  us/call  us/call  name    
100.00      1.98     1.98    99999    19.80    19.80  lpd
  0.00      1.98     0.00    99999     0.00     0.00  spd
```

Clearly, lpd() is the source of inefficiency of our program. A more efficient implementation of lpd() would be:
```c
int lpd(int n)
{
    int nByDiv = spd(n);
    if (nByDiv)
        return n / nByDiv;
    else
        return 0;
}
```

Q3)

A part (contiguous) of the output supplied by gprof:
```gprof
----------------------------------------------------
               0.00     0.00    7/19      main [9]
               0.00     0.00    12/19     f1 [3]
[2]    0.0     0.00     0.00    19     f2 [2]
               0.00     0.00    19/40     f3 [1]
----------------------------------------------------
```

- main() calls f2() 7 out of total 19 times, ∴ **x+z=7**.

- f1() calls f2() 12 times, which means f1() itself was called for a total of 12 times, ∴ **x+y=12**

- f3() was called by f2() 19 times and by f1() 12 times out of total 40 times, ∴ **y+z=40-19-12=9**

∴ **x=5,    y=7,    z=2**
