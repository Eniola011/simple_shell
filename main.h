#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

extern char **environ;

#define _BUFFY_ 1024
#define _ERR_    0
#define _NORMAL_ 1
#define _SKIP_   2
#define _SHELL_END_  3
#define _BUILT_IN_  4
#define _PATH_NREADY_  5
#define _PATH_READY_  6
#define UNUSED _attribute_((unused))

/**
 * execmd - execute commands
 * @program: string
 * @args: arguments
 * Return: no value
 */

void execmd(char *progrm, char **args);

/**
 * _strtok - gets strings
 * @buf: strings inputted
 * @delimiter: separator
 * Return: array of strings
 */

char **_strtok(char **buf, char *delimiter);

/**
 * _stralloc - link string
 * @counter: string
 * Return: linked strings
 */

char *stralloc(int counter,...);

/**
 * get_line - determine number of tokens.
 * @strng: inputted string
 * @delim: separates string
 * Return: number of strings.
 */

int get_line(char *strng, char *delim);
int _strlen(char*);
int _strcmp(char *, char*);
char *_strcat(char *, char *);
char *_strstr(char *, char*);
char *_strcpy(char *, char*);

/**
 * get_path - get path for the program.
 * @program: token
 * *Return: full path.
 */

char *grt_path(char *program);

/**
 * find_path - find path
 * @pathenviron: path token array
 * @progrm: string
 * Return: complete path
 */

char *find_path(char **pathenviron, char *program);

/**
 * check_argmt - check arguments inputted.
 * @argumt: arguments
 * Return: success(1), fail(0).
 */

unsigned int check_argmt(char *argumt);

/**
 * env_key - key for environment
 * @kii: key
 * Return: env
 */

char *env_key(char *kii);

/**
 * struct _builtin - handles builtin functions.
 * @cmd: inputted commands
 * @funt: function pointer
 *
 */

typedef struct _builtin

{
	char *cmd;
	int (*funt)(char **);
builts;

/**
 * builtin - check for builtin functions.
 * @argument: argument
 * Return: the status code
 */

int builtin(char **argument);
int envprint(char **);
int envcmd(char **);
int sh_exit(char **);

#endif
