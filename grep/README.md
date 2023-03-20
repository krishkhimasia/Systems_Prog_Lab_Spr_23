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
```bash
grep '^[<TAB>].*' example.txt
```
(b) 
```bash
grep -e 'foo' -e 'bar' example.txt
```
(c) 
```bash
grep -e '.*foo.*bar.*' -e '.*bar.*foo.*' example.txt
```
(d) 
```bash
grep '.*foobar.*' example.txt
```
(e) Both "**foobar bar**" and "**foo foobar**" will match.
```bash
grep '.*foo..*bar.*' example.txt
```

Q3) Obviously the printf will occur first in line (or after some tabs)
```bash
grep '^[<TAB>]*printf' example.c
```

Q4?)

Q5)

(a) 
```bash
grep -v '876' foonums.txt
```
(b) 
```bash
grep -w -v -e '[5-9][0-9][0-9]' -e '[1-4][0-9][0-9][0-9]' -e '5000' foonums.txt
```
(c?) 
```grep

```
(d?)
```grep

```

Q6)
```bash
ls -l | grep '^...x'
```

Q7)
```bash
ls -l | grep '.* .* .* .* [1-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]*'
```

Q8)

(a)
```bash
grep '^....:x:' /etc/passwd
```

(b)
```bash
grep '/bin/bash$' /etc/passwd
```
