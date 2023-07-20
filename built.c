#include "main.h"

/**
 * builtin_command - check for builtin functions.
 * @arg: argument.
 * Return: the status code.
 */
void builtin_command(char **arg)
{
	int shell_builtin = 0, index;

	struct builtins built[] = {
		{"exit", shell_exit},
		{"cd", shell_cd},
		{"help", shell_help},
		{"env", shell_env},
	};

	shell_builtin = sizeof(built) / sizeof(struct builtins);

	for (index = 0; index < shell_builtin; index++)
	{
		if (_strcmp(arg[0], built[index].cmd) == 0)
		{
			built[index].funt(arg);
			return;
		}
	}
}

/**
 * shell_exit - leaves shell program.
 * @arg: array of arguments.
 * Return: zero
 */
void shell_exit(char **arg)
{
	(void)arg;
	exit(0);
}

/**
 * shell_cd - change of directories.
 * @arg: array of arguments.
 * Return: no value
 */
void shell_cd(char **arg)
{
	if (arg[1] == NULL)
	{
		fprintf(stderr, "hsh: cd: argument missing\n");
	}
	else
	{
		if (chdir(arg[1]) != 0)
		{
			perror("hsh: cd");
		}
	}
}

/**
 * shell_help - helps user
 * @arg: argument
 * Return: no value
 */
void shell_help(char **arg)
{
	char *message =
		"These are the available commands to use:\n"
		"  cd       Change your working directory.\n"
		"  exit     leave the shell.\n"
		"  help     output this help message.\n";
	printf("%s", message);

	(void)arg;
}

/**
 * shell_env - outputs the environment
 * @arg: array of arguments
 * Return: no value
 */
void shell_env(char **arg)
{
	char **envp = environ;

	while (*envp)
	{
		printf("%s\n", *envp++);
	}

	(void)arg;
}
