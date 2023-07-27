#include "main.h"

/**
 * dup_info - duplicates info for new env
 * @tag: name of env/alias
 * @val: value of env/alias
 * Return: new env/alias
 */
char *dup_info(char *tag, char *val)
{
	char *n;
	int len_tag, len_val, len;

	len_tag = _strlen(tag);
	len_val = _strlen(val);
	len = len_tag + len_val + 2;
	n = malloc(sizeof(char) * (len));
	_strcpy(n, tag);
	_strcat(n, "=");
	_strcat(n, val);
	_strcat(n, "\0");

	return (n);
}

/**
 * set_environ - sets env var
 * @tag: name of env var
 * @val: value of env var
 * @data: data
 * Return: no value
 */
void set_environ(char *tag, char *val, list_sh *data)
{
	int a;
	char *varenv, *tagenv;

	for (a = 0; data->_env[a]; a++)
	{
		varenv = _strdup(data->_env[a]);
		tagenv = _strtok(varenv, "=");
		if (_strcmp(tagenv, tag) == 0)
		{
			free(data->_env[a]);
			data->_env[a] = dup_info(tagenv, val);
			free(varenv);
			return;
		}
		free(varenv);
	}

	data->_env = _reallocdp(data->_env, a, sizeof(char *) * (a + 2));
	data->_env[a] = dup_info(tag, val);
	data->_env[a + 1] = NULL;
}

/**
 * _setenv - env variables
 * @data: data
 * Return: success(1)
 */
int _setenv(list_sh *data)
{

	if (data->argc[1] == NULL || data->argc[2] == NULL)
	{
		find_error(data, -1);
		return (1);
	}

	set_environ(data->argc[1], data->argc[2], data);

	return (1);
}

/**
 * _unsetenv - delete env variable
 * @data: data
 * Return: success(1)
 */
int _unsetenv(list_sh *data)
{
	char **realloc_env;
	char *varenv, *tagenv;
	int a, b, c;

	if (data->argc[1] == NULL)
	{
		find_error(data, -1);
		return (1);
	}
	c = -1;
	for (a = 0; data->_env[a]; a++)
	{
		varenv = _strdup(data->_env[a]);
		tagenv = _strtok(varenv, "=");
		if (_strcmp(tagenv, data->argc[1]) == 0)
		{
			c = a;
		}
		free(varenv);
	}
	if (c == -1)
	{
		find_error(data, -1);
		return (1);
	}
	realloc_env = malloc(sizeof(char *) * (a));
	for (a = b = 0; data->_env[a]; a++)
	{
		if (a != c)
		{
			realloc_env[b] = data->_env[a];
			b++;
		}
	}
	realloc_env[b] = NULL;
	free(data->_env[c]);
	free(data->_env);
	data->_env = realloc_env;

	return (1);
}
