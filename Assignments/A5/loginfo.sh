#!/bin/bash

if [ $# -eq 1 ]     # to decide whether S will contain all records or just last N records
then
    N=$1
    S=`last -w -$N`     # -w command-line option used to get full names of users
else
    S=`last -w`
fi

A=()        # quick declaration array of strings A

while read -r line; do      # using read with <<< redirection to populate A
    A+=("$line")
done <<< "$S"

numofrecs=$((${#A[@]}-2))       # numofrecs = no. of lines outputted by last - 2

declare -A H=()     # declared associative array H

for((i=0;i<numofrecs;++i))      # loop to populate H with usernames extracted using regex
do
    if [[ ${A[$i]} =~ ^([a-zA-Z0-9]*)(.*)$ ]]; then
        H[${BASH_REMATCH[1]}]=$((H[${BASH_REMATCH[1]}]+1))
    fi
done

echo "$numofrecs login records read"

for name in ${!H[@]}; do        # printing users and no. of logins
    echo "$name logged in ${H[$name]} times"
done