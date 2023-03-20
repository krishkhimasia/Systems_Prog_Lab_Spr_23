Q1)

(a) [^AEIOUaeiou]

(b) [^AEIOUaeiou][^AEIOUaeiou]*

(c) [^AEIOUaeiou]\* [AEIOUaeiou] [^AEIOUaeiou]\*

(d) [^AEIOUaeiou]\* [AEIOUaeiou] [AEIOUaeiou] [^AEIOUaeiou]\*

(e) [^AEIOUaeiou]\* [AEIOUaeiou]+ [^AEIOUaeiou]\*

(f) [A-Za-z]*

(g) ^[A-Za-z]*$

(h) 0x[0-9A-Fa-f][0-9A-Fa-f]\*

(i) ^(.* ){10,}.*$

(j) ^(.*[^ ]){10,}.$

Q2)

(a) 
```grep
grep '^[<TAB>].*' example.txt
```
(b) 
```grep
grep -e 'foo' -e 'bar' example.txt
```
(c) 
```grep
grep -e '.*foo.*bar.*' -e '.*bar.*foo.*' example.txt
```
(d) 
```grep
grep '.*foobar.*' example.txt
```
(e) Both "**foobar bar**" and "**foo foobar**" will match.
```grep
grep '.*foo..*bar.*' example.txt
```

Q3) Obviously the printf will occur first in line (or after some tabs)
```grep
grep '^[<TAB>]*printf' example.c
```

Q4?)

Q5)

(a) 
```grep
grep -v '876' foonums.txt
```
(b) 
```grep
grep -w -v -e '[5-9][0-9][0-9]' -e '[1-4][0-9][0-9][0-9]' -e '5000' foonums.txt
```
(c?) 
```grep

```
(d?)
```grep

```
