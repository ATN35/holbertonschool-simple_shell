# C - Simple Shell

## Description :

The **Simple Shell** is a [Holberton School](https://www.holbertonschool.com "Holberton School") project, it simulates a basic **Unix Shell** with its respective commands. It uses the POSIX API to implement many of the same functionalities of the first Ken Thompson's Shell.

## Requirements :

### General :

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded

### Github :

There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

### More Info :

Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

### List of allowed functions and system calls

```
* access (man 2 access)
* chdir (man 2 chdir)
* close (man 2 close)
* closedir (man 3 closedir)
* execve (man 2 execve)
* exit (man 3 exit)
* _exit (man 2 _exit)
* fflush (man 3 fflush)
* fork (man 2 fork)
* free (man 3 free)
* getcwd (man 3 getcwd)
* getline (man 3 getline)
* getpid (man 2 getpid)
* isatty (man 3 isatty)
* kill (man 2 kill)
* malloc (man 3 malloc)
* open (man 2 open)
* opendir (man 3 opendir)
* perror (man 3 perror)
* read (man 2 read)
* readdir (man 3 readdir)
* signal (man 2 signal)
* stat (__xstat) (man 2 stat)
* lstat (__lxstat) (man 2 lstat)
* fstat (__fxstat) (man 2 fstat)
* strtok (man 3 strtok)
* wait (man 2 wait)
* waitpid (man 2 waitpid)
* wait3 (man 2 wait3)
* wait4 (man 2 wait4)
* write (man 2 write)
```

## How to use our shell :

- In order to run this program, you have to start by cloning this repository with:
```
git clone https://github.com/ATN35/holbertonschool-simple_shell.git
```

- Then compile it with:
```
gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh
```

- You can now use it by invoking:
```
./hsh
```

- If you want to check memory leaks use:
```
valgrind --leak-check=full ./hsh
```

- We provided a simple manual to know and get familiar with our shell. Open it by typing:
```
man ./man_1_simple_shell
```

## Return from a shell function :

A return command is used to exit from a shell function. It takes a parameter [N], if N is mentioned then it returns [N] and if N is not mentioned then it returns the status of the last command executed within the function or script. N can only be a numeric value.
Note that **echo $?** can be used to display the last return status.

## Examples :

### In interactive mode
- with pwd
```
username@your-regular-prompt:/holbertonschool-simple_shell# ./hsh
$ pwd
/holbertonschool-simple_shell
$
```

- with ls
```
username@your-regular-prompt:/holbertonschool-simple_shell# ./hsh
$ ls
AUTHORS  EOF.c  README.md  environ.c  errors.c  execute.c  exit.c  fork.c  frees.c  gen-authors  hsh  main.c  path.c  prompt.c  shell.h  strfunct.c  tokenize.c
$
```

- with exit
```
username@your-regular-prompt:/holbertonschool-simple_shell# ./hsh
$ exit
username@your-regular-prompt:/holbertonschool-simple_shell#
```

### In non-interactive mode
- with echo "/bin/ls" | ./hsh
```
username@your-regular-prompt:/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS  environ.c  EOF.c  errors.c  execute.c  exit.c  fork.c  frees.c  gen-authors  hsh  main.c  path.c  prompt.c  README.md  shell.h  strfunct.c  tokenize.c
$
```

## To compare with the basic Unix Shell :

### In interactive mode
- with pwd
```
username@your-regular-prompt:/holbertonschool-simple_shell# pwd
/holbertonschool-simple_shell
username@your-regular-prompt:/holbertonschool-simple_shell#
```

- with ls
```
username@your-regular-prompt:/holbertonschool-simple_shell# ls
AUTHORS  EOF.c  README.md  environ.c  errors.c  execute.c  exit.c  fork.c  frees.c  gen-authors  hsh  main.c  path.c  prompt.c  shell.h  strfunct.c  tokenize.c
username@your-regular-prompt:/holbertonschool-simple_shell#
```

### In non-interactive mode
- with echo "/bin/ls" | /bin/sh
```
username@your-regular-prompt:/holbertonschool-simple_shell# echo "/bin/ls" | /bin/sh
AUTHORS  environ.c  EOF.c  errors.c  execute.c  exit.c  fork.c  frees.c  gen-authors  hsh  main.c  path.c  prompt.c  README.md  shell.h  strfunct.c  tokenize.c
username@your-regular-prompt:/holbertonschool-simple_shell#
```

## Files :

* `README.md` : current file, contains information about this project
* `shell.h` : header file, contains all prototypes and libriaries
* `main.c`: main function, runs our shell
* `prompt.c`: print the prompt in the terminal
* `fork.c` : creates a child process
* `execute.c`: executes the program and kill the child
* `frees.c`: contains the free functions we created
* `exit.c`: exit our shell when 'exit' is typed
* `EOF.c`: exit our shell when 'End Of File'
* `errors.c`: manages the errors
* `environ.c`: contains the function that prints the environment
* `path.c`: manages the path
* `tokenize.c`: tokenize the string of input
* `otherfunct.c`: standard functions we had to create
* `man_1_simple_shell`: manual of our shell
* `gen-authors`: file that generate the AUTHORS file
* `AUTHORS`: file containing the name of the crontributors to this repo


## Bugs :

We are still reviewing our code in order to exeterminate our bugs.

*For More Informations Check The Man Page*

## Authors

Antoine Lelièvre & Maxence Thibault