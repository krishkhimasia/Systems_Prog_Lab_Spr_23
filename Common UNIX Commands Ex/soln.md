<p>

Q1) 

    /usr has r permission for all users, /root does not.

Q2) 

    `$ man man` gives manual page for man command itself, which includes the following:
    
    The list below shows the section numbers of the manual followed by the types of pages they contain:
    
    a   Executable programs or shell commands
    
    b   System calls (functions provided by the kernel)
    
    c   Library calls (functions within program libraries)
    
    d   Special files (usually found in /dev)
    
    e   File formats and conventions, e.g. /etc/passwd
    
    f   Games
    
    g   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7), man-pages(7)
    
    h   System administration commands (usually only for root)
    
    i   Kernel routines [Non standard]
    
    Hence `$ man printf` is for the "printf" shell command, while `$ man 3 printf` is for the printf() function in C library.

Q3)

    Separate each command by semicolon (;) or &&

Q4) 

    using a backslash:

``` bash
$ ls \
> -l
```



Q5,6,7) 

    Ctrl - D signals EOF (end of file). ^D told the shell that you weren't going to type any more commands.
      
    Ctrl - C means "interrupt", it terminates the command.

Q8) 

    The first `wc` takes output of `ls -l` as its input, and the corresponding output is piped into the second `wc` as its input.

Q9) 
    
    a)`du` estimates file space usage, but lists only space taken by directories.
      
    b)`du -a` writes counts for all files, not just directories.
       
    c)`du -s` displays only total size for each argument. If no argument given, it displays total size of curent directory.
      
    d)`du -sk` displays total size in KBs
      
    e)`du -sm` displays total size in MBs.
      
    f)`du -sh` displays total size in human readable form with appropriate unit (KB,MB,GB).

*Q10) 

    'd' file type indicates directory.
    
    'c' file type indicates character special file.
    
    'l' file type indicates symbolic link.

*Q11) 

    The fifth field in the output of `ls -l` specifies the number of links or directories inside this directory.
    
    If you create a file, its link count is 1 by default.
    
    If you create a directory "xyz", the default link count of it is 2. The extra count is because for every directory created, a link gets created in the parent directory to point to this new directory.

```bash
$ mkdir xyz
$ ls -ld xyz
 
drwxrwxr-x 2 krish krish 4096 Jan  9 14:21 xyz
```



Q12) 

```bash
$ vim testfile.txt # creates the required non empty file.

$ ls -l

-rw-rw-r-- 1 krish krish 17 Jan  9 14:29 testfile.txt

$ ln -s testfile.txt T # creates a symbolic link 'T' to 'testfile.txt'.
```

  

```bash
$ ls -l

lrwxrwxrwx 1 krish krish 12 Jan  9 14:50 T -> testfile.txt  # (T is light blue color here)
  
-rw-rw-r-- 1 krish krish 17 Jan  9 14:29 testfile.txt

$ chmod 000 T # changes the permissions of the file which T points to (testfile.txt).

# If a symbolic link is deleted, its target remains unaffected.

# If another symbolic link 'TT' pointing to 'testfile.txt' is created and 'testfile.txt' is removed, then the symlink is not updated or deleted, and points to the old,non-existing location.
```

Q13) 

    ```bash
    $ ls -l
    ```

​    

```bash
-rw-rw-r-- 1 krish krish 13 Jan  9 15:05 abc.txt
```


​    
```bash
$ ln abc.txt ABC.txt

$ ls -l

-rw-rw-r-- 2 krish krish 13 Jan  9 15:05 abc.txt

-rw-rw-r-- 2 krish krish 13 Jan  9 15:05 ABC.txt
 
 # Notice that the link count for both are 2.
 # After adding some lines to 'abc.txt' and seeing directory listing:
 
 $ ls -l
 
 -rw-rw-r-- 2 krish krish 47 Jan  9 15:10 abc.txt
 -rw-rw-r-- 2 krish krish 47 Jan  9 15:10 ABC.txt
 
# So 'ABC.txt' updates according to the changes to 'abc.txt'
 
# 'ABC.txt' remains unnaffected after removing 'abc.txt', but its link count now becomes 1.
# Hence, if the original file is deleted, the data still exists under the secondary hard link.
```

Q14)

    a) pwd : Prints current working directory.
     
    b) chmod -R : chmod changes file mode bits. If you use chmod on a directory, it changes permissions for thet directory, but the permissions for its contents remain unaffected. Using chmod -R will recursively change the permissions of the contents of the directory as well.
    
    c) chown : Changes owner of file/directory.
    
    d) chgrp : Changes group owner of file/directory.
    
    e) date : print or set the system date and time.
    
    f) time : runs programns and summarizes system resource usage.
    
    *g) strings : it extracts printable characters from files so that other commands can use the strings without non-printable characters.
    
    h) exit : Exits the shell.

Q15) 

```bash
$ cal 1752 # prints the calendar of 1752.
```
```
The eleven days (3rd to 13th) here are the 'lost' 11 days of September 1752, skipped when Britain changed over from the Julian calendar to the Gregorian calendar, bringing them into line with most of Europe.
```

