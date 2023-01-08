1) /usr has r permission for all users, /root does not.

2)  $ man man
   - gives manual page for man command itself, which includes the following:
    The table below shows the section numbers of the manual followed by the types of pages they contain.

       1   Executable programs or shell commands
       2   System calls (functions provided by the kernel)
       3   Library calls (functions within program libraries)
       4   Special files (usually found in /dev)
       5   File formats and conventions, e.g. /etc/passwd
       6   Games
       7   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7), man-pages(7)
       8   System administration commands (usually only for root)
       9   Kernel routines [Non standard]

    Hence $ man printf if for the "printf" shell command, while $ man 3 printf is for the printf() function in C library.
