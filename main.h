#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFF 1024
#define TOKEN_BUFFSIZE 128
#define TOKEN_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct statis - struct that contains all relevant data on runtime
 * @argv: argument vector
 * @input: inputted string
 * @argc: argument count
 * @status: last status of the shell
 * @count: nread
 * @_env: environment variable
 * @pidd: process ID of the shell
 */
typedef struct statis
{
	char **argv;
	char *input;
	char **argc;
	int status;
	int count;
	char **_env;
	char *pidd;
} list_sh;

/**
 * struct linelist - single linked list
 * @lineptr: command line
 * @next: next node
 * Description: singly linked list to store command lines
 */
typedef struct linelist
{
	char *lineptr;
	struct linelist *next;
} cmd_list;

/**
 * struct vari_list - single linked list
 * @varlen: var len
 * @value: value
 * @valuelen: value len
 * @next: next node
 * Description: singly linked list to store variables
 */
typedef struct vari_list
{
	int varlen;
	char *value;
	int valuelen;
	struct vari_list *next;
} varb_list;

/**
 * struct strng_list - linked list
 * @sep: ; | &
 * @next: next node
 * Description: singly linked list to store separator command
 */
typedef struct strng_list
{
	char sep;
	struct strng_list *next;
} sep_list;

/**
 * struct builtins - handles builtin functions.
 * @tag: commands
 * @funt: function pointer
 *
 */
typedef struct builtins
{
	char *tag;
	int (*funt)(list_sh *argmt);
} built_in;

int repeat_chr(char *chr, int i);
int _error(char *str, int i, char tok);
int first_chr(char *str, int *i);
void print_syntaxerror(list_sh *data, char *str, int i, int bull);
int check_syntaxerror(list_sh *data, char *str);
char *_comment(char *token);
void hsh_loop(list_sh *data);
char *read_a_line(int *nread);

sep_list *add_node(sep_list **h, char s);
void free_seplist(sep_list **h);
cmd_list *add_line(cmd_list **h, char *n);
void free_linelist(cmd_list **h);
varb_list *add_var_node(varb_list **h, int n, char *v, int len);
void free_var_list(varb_list **h);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *acc);
void _memcpy(void *dest, const void *src, unsigned int n);
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize);
char **_reallocdp(char **ptr, unsigned int oldsize, unsigned int newsize);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmpchr(char strng[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void rev_string(char *s);
int _strnlen(int n);
char *_itoa(int n);
int _atoi(char *s);
char *strcat_cdr(list_sh *, char *, char *, char *);

char *dup_char(char *tok, int bull);
void addanodes(sep_list **head1, cmd_list **head2, char *strng);
void _next(sep_list **list_s, cmd_list **list_l, list_sh *data);
int split_cmds(list_sh *data, char *str);
char **splitline(char *strng);

void find_env(varb_list **h, char *str, list_sh *data);
int find_varb(varb_list **h, char *str, char *sts, list_sh *data);
char *replace_token(varb_list **h, char *tok, char *new_tok, int sum_b);
char *replace_var(char *token, list_sh *data);

void _line(char **line, size_t *n, char *buff, size_t i);
ssize_t _getline(char **line, size_t *n, FILE *strm);
int exec(list_sh *data);
int isit_cdir(char *p, int *a);
char *_locate(char *cmd, char **env);
int isit_executable(list_sh *data);
int error_cmd(char *diry, list_sh *data);
int exec_cmmd(list_sh *data);

char *_getenv(const char *name, char **_environ);
int _env(list_sh *data);

char *dup_info(char *tag, char *val);
void set_environ(char *tag, char *val, list_sh *data);
int _setenv(list_sh *data);
int _unsetenv(list_sh *data);

void cddot(list_sh *data);
void cdgo(list_sh *data);
void cdprv(list_sh *data);
void cdhome(list_sh *data);
int shell_cd(list_sh *data);
int (*find_builtin(char *cmd))(list_sh *);
int exit_sh(list_sh *data);

char *error_cd(list_sh *data);
char *not_found(list_sh *data);
char *exit_shell(list_sh *data);
char *get_alias(char **argc);
char *env_error(list_sh *data);
char *syntax_error(char **argc);
char *error_permission(char **argc);
char *error_126(list_sh *data);
int find_error(list_sh *data, int errval);
void find_sigint(int signl);

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_general(void);
void help_exit(void);
void _help(void);
void help_alias(void);
void help_cd(void);
int find_help(list_sh *data);



#endif