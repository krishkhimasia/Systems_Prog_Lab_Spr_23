
Q1)  Change the if-else block as follows:
```gawk
if ((ts <= 252) && (te >= 201)) { nt++; sumt += $3 }
    else if ((ts <= 201) && (te >= 145)) { nj++; sumj += $3 }
    else if ((ts <= 145) && (te >= 65)) { nc++; sumc += $3 }
    else if(ts>=201) {
        nt++
        sumt +=3 
        if(te<=201) {
            nj++
            sumj +=3
        }
        if(te<=145) {
            nc++
            sumc +=3
        }
    }
    else if(ts>=145) {
        nj++
        sumj +=3
        if(te<=145) {
            nc++
            sumc +=3
        }
    }
```

Q2) Change the END block as follows:
- asorti(tlist,nlist) creates sorted array 'nlist' of the indices of tlist.
- Use this array to print nlist in order of countries sorted alphabetically.
```gawk
END {
    asorti(tlist,nlist)
    for (c in nlist) {
        printf("%-15s: %s\n", nlist[c], tlist[nlist[c]])
    }
}
```

Q3)

```gawk
# dinotypes.awk
BEGIN{
    FS = ":"
}

{
    A[$2]=A[$2] "," $1
}

END{
    for (i in A) {
        print i ":"
        size = split(A[i], B, ",")
        for (j = 2; j <= size; j++) {
            print "\t" B[j]
        }
        print "Total count = " size-1 "\n"
    }
}
```

Q4)
```gawk
# sortsauropods.awk
BEGIN {
    FS = ":"
}

{
    if ($2=="sauropod") {
        ind=index($6,"-")
        if(ind==0) {
            liv=int($6)
        }
        else {
            l=int(substr($6,1,ind-1))
            r=int(substr($6,ind+1, length($6)-ind))
            liv=((l+r)/2)
        }
        A[liv] = A[liv] "\n" $1 ":\n\tLiving time: " liv " million years ago\n\tLength: " $3
    }
}

END{
    asorti(A, B)
    for (i in B) {
        print A[B[i]]
    }
}
```

Q5)
```gawk
#nonsys.awk
BEGIN{
    FS = ":"
    print "Non-system users:-"
}
{
    if(int($3) >= 1000){
        print $1
    }
}
```

Q6)
```gawk
BEGIN{
    FS = ":"
}

{
    shells[$7]=shells[$7] " " $1
}

END{
    for(shell in shells)
    {
        print "login shell: " shell
        print "\t" shells[shell]
    }
}
```
