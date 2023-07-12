# SIMPLE SHELL PROJECT
* This is how to create a simple unix command interpreter using C language.
* The program has the basic features of unix terminals like linux, ubuntu.
* The program was written in C (C99) language and tested on ubuntu 20.04..
* This is project was created by Adula Janet and Agbalu Eniola as part of the ALX SE program.
* The project was compiled using "gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o hsh"

## Description of the project
**This shell program is named "hsh" and it is expected to the following listed below:
* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines are made only of one word. No arguments will be passed to programs.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors, the “end of file” condition (Ctrl+D).
* Handle command lines with arguments.
* Handle the PATH, fork must not be called if the command doesn’t exist.
* Implement the exit built-in, that exits the shell.
* Implement the env built-in, that prints the current environment.
* Handle arguments for the built-in exit.
* Implement the setenv and unsetenv builtin commands.
* Implement the builtin command cd.

### Requirements for the project.
**We were instructed to the following:
* Editors to use: vi, vim, or emacs.
* All our files were to be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.
* All our files were to end with a new line.
* Our code should use the Betty style and will be checked using betty-style.pl and betty-doc.pl.
* Our shell should not have any memory leaks.
* We should have no more than 5 functions per file.
* We should use system calls only when we need to.
* We did not have to handle any argument to our shell built-in exit.
* We were required to use the functions below from C libraries. We had to create our "strlen, strcmp, strtok, getline, strcat, strcpy, strstr."
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

### Compilation
** Our shell "hsh" program is expected to work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
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
```

### Authors
* Janet Adula <[Jannydear](https:github.com/Jannydear)>
* Agbalu Eniola <[Eniola011](https:github.com/Eniola011)>


