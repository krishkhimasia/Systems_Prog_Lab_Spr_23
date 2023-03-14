
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
