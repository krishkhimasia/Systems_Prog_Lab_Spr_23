#!/bin/bash

if [ $# -eq 0 ]     # to handle N<=0 case
then
    echo "Run fibrep.sh with a single positive integer argument"
	exit 1
elif [ $1 -lt 0 ]
then
    echo "Invalid argument $1 to fibrep.sh"
	exit 1
fi

N=$1        # assigning N the first command line argument

if  [ $N -eq 0 ]        # handled case of 0 separately
then
    declare -ia F=(0)
    echo "Computed Fibonacci numbers up to F(0) = ${F[0]}"
    echo -n "$N = " 
    echo -n "F(0)"

else
    declare -ia F=(0 1)     # declared the fibonacci array

    t=2         # iterator used to add valued to the fibonacci array

    while true      # loop generates fibonacci numbers until F(t)>=N
    do
        F[$t]=$((F[t-1]+F[t-2]))
        if [ ${F[$t]} -ge $N ]
        then
            echo "Computed Fibonacci numbers up to F($t) = ${F[$t]}"
            break
        fi
        t=$((t+1))
    done

    echo -n "$N = "             # Printing of main output starts

    if [ ${F[$t]} -le $N ]      # to start the printing of the rhs of N = F() + ...
    then
        echo -n "F($t)"
        N=$((N-F[$t]))
    else
        t=$((t-1))
        echo -n "F($t)"
        N=$((N-F[$t]))
    fi

    while [ $N -gt 0 ]      # prints rest of the appropriate F()
    do
        if [ ${F[$t]} -le $N ]
        then
            echo -n " + F($t)"
            N=$((N-F[$t]))
        else
            t=$((t-1))
        fi
    done
fi
echo ""     # added just so that shell is in new line after completion