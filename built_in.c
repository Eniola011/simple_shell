#include "main.h"

/**
 * builtin - check for builtin functions.
 * @argument: argument.
 * Return: the status code.
 */
int builtin(char **argument)
{
	int index = 0;
	builts builtfunc[] = {
		{"env", envprint},
		{"exit", sh_exit},
		{"cd", envcmd},
		{NULL, NULL}
	};

	while (builtfunc[index].cmd != NULL)
	{
		if (_strcmp(argument[0], builtfunc[index].cmd) == 0)
		{
			return (builtfunc[index].funt(argument));
		}
		index++;
	}
	return (1);
}

/**
 * envprint - outputs the environment
 * @argmt: array of arguments
 * Return: success(_SKIP_)
 */
int envprint(__attribute__((unused))char **argmt)
{
	int n = 0;
	int length;

	while (environ[n] != NULL)
	{
		length = _strlen(environ[n]);
		write(STDOUT_FILENO, environ[n], length);
		write(STDOUT_FILENO, "\n", 1);
		n++;
	}
	return (2);
}

/**
 * sh_exit - leave shell program.
 * @argmts: array of arguments.
 * Return: success(_SHELL_END_)
 */
int sh_exit(__attribute__((unused))char **argmts)
{
	return (3);
}

/**
 * envcmd - change of directories.
 * @arg: array of arguments.
 * Return: success(_SKIP_)
 */
int envcmd(char **arg)
{
	int status;

	if (arg[1] == NULL)
	{
		status = chdir(env_key("HOME"));
	}
	else if (_strcmp(arg[1], "-") == 0)
	{
		status = chdir(env_key("OLDPWD"));
	}
	else
	{
		status = chdir(arg[1]);
	}


	if (status == -1)
	{
		perror("dir has an error.");
	}
	return (2);
}
