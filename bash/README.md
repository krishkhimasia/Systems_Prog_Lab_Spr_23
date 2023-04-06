1. checkfib.sh 
```bash
#!/bin/bash
#checkfib.sh

function generatefib () {
    local n=$1
    for((i=2; i<n; ++i)) do
        F[i]=F[i-1]+F[i-2]
    done
}

if [ $# -eq 0 ]
then
	echo "usage: $0 <list of numbers>"
	exit 1
fi

declare -ia F=(0 1)
N=20
generatefib N
for n in $@
do
    for((i=0;i<N;++i)) do
        if [ ${F[i]} -eq $n ]; then
            echo "$n is in the fibonacci series"
            break
        fi
        if [ $i -eq $((N-1)) ]; then
            echo "$n is not in the fibonacci series"
        fi
    done
done
        
```
- Usage: `./checkfib.sh <list of numbers>`
- Make sure checkfib.sh has the necessary execution permissions. If not, it can be given permission by running the command `chmod +x checkfib.sh`
