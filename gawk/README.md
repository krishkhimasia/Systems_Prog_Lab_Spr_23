
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
