#include "main.h"

/**
 * envcmpr - compare env var names
 * @tagenv: name of env var
 * @tag: name passed
 * Return: zero
 */
int envcmpr(const char *tagenv, const char *tag)
{
	int a;

	for (a = 0; tagenv[a] != '='; a++)
	{
		if (tagenv[a] != tag[a])
		{
			return (0);
		}
	}

	return (a + 1);
}

/**
 * _getenv - get env var
 * @tag: name of env var
 * @env: env var
 * Return: value of env var
 */
char *_getenv(const char *tag, char **env)
{
	char *envptr;
	int a, cpy;

	envptr = NULL;
	cpy = 0;

	for (a = 0; env[a]; a++)
	{
		cpy = envcmpr(env[a], tag);
		if (cpy)
		{
			envptr = env[a];
			break;
		}
	}

	return (envptr + cpy);
}

/**
 * _env - print env var
 * @data: data
 * Return: success(1)
 */
int _env(list_sh *data)
{
	int a, b;

	for (a = 0; data->_env[a]; a++)
	{

		for (b = 0; data->_env[a][b]; b++)
			;

		write(STDOUT_FILENO, data->_env[a], bb);
		write(STDOUT_FILENO, "\n", 1);
	}
	data->status = 0;

	return (1);
}
