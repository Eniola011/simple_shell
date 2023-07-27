#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/**
 * struct builtins - handles builtin functions.
 * @cmd: inputted commands
 * @funt: function pointer
 *
 */
struct builtins
{
	char *cmd;
	void (*funt)(char **argmt);
};

char **get_token(char *line, ssize_t nread);
char *read_a_line(ssize_t *nread);
int exec_cmd(char **token);

void builtin_command(char **arg);
void shell_exit(char **arg);
void shell_cd(char **arg);
void shell_help(char **arg);
void shell_env(char **arg);

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
void _memcpy(void *dest, const void *src, unsigned int n);
char *_strdup(const char *s);

char *find_path(char *cmd);

#endif
