
Q1)

```bash
# create first profile-data file gmon.out
gprof ./secretapp gmon.out

# rename it to gmon.sum
mv gmon.out gmon.sum

# Merge the new data in gmon.out into gmon.sum using -s flag, repeat this 9 more times
gprof -s executable-file gmon.out gmon.sum
```
