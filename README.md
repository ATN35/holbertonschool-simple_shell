# Simple Shell

The Simple Shell is a basic command-line interpreter designed to execute system commands. It allows the user to enter commands and executes them by creating child processes for each command.

## Features

- Displaying a prompt for entering commands.
- Tokenization: Breaking down commands into individual tokens.
- Creating child processes to execute commands.
- Handling execution of system commands.
- Displaying results of executed commands.

## Rule

List of allowed functions and system calls+
all functions from string.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

## Usage

1. Clone the repository:
git clone https://github.com/ATN35/holbertonschool-simple_shell.git

2. Compile the shell:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

3. Run:
./hsh

4. Enter commands:
[interactive]
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
[non-interactive]
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$


## Contributors

Antoine Lelievre - https://github.com/ATN35

## License

This project is licensed under the GNU General Public License (GPL).

---

Created as part of Simple Shell - Holberton School.
