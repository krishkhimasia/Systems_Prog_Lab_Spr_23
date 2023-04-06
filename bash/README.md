1. checkfib.sh 
```bash
#!/bin/bash

generatefib(){
	n=$1
	F=(0 1)
	for((i=2; i<n; i++)); do 
		F[$i]=$((F[i-1]+F[i-2])) 
	done
	echo ${F[@]}
}

if [ $# -eq 0 ]
then
	echo "usage: $0 <list of numbers>"
	exit 1
fi

# 20 chosen arbitrarily to generate a series of 20 numbers
fib=`generatefib 20`

for i in $@
do
	# check if the number is in the series
	if [[ $fib =~ $i ]]
	then
		echo "$i is in the fibonacci series"
	else
		echo "$i is not in the fibonacci series"
	fi
done
```
- Usage: `./checkfib.sh <list of numbers>`
- Make sure checkfib.sh has the necessary execution permissions. If not, it can be given permission by running the command `chmod +x checkfib.sh`
