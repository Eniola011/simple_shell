#include "main.h"

/**
 * freedata - release data
 * @data: data
 * Return: no value
 */
void freedata(list_sh *data)
{
	unsigned int i;

	for (i = 0; data->_env[i]; i++)
	{
		free(data->_env[i]);
	}

	free(data->_env);
	free(data->pidd);
}

/**
 * setdata - sets data
 * @data: data
 * @argmt: argument vector
 * Return: no value
 */
void setdata(list_sh *data, char **argmt)
{
	unsigned int i;

	data->argv = argmt;
	data->input = NULL;
	data->argc = NULL;
	data->status = 0;
	data->count = 1;

	for (i = 0; environ[i]; i++)
		;

	data->_env = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->_env[i] = _strdup(environ[i]);
	}

	data->_env[i] = NULL;
	data->pidd = aux_itoa(getpid());
}

/**
 * main - step 1
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: success(0).
 */
int main(int argc, char **agrv)
{
	list_sh data;
	(void) argc;

	signal(SIGINT, find_sigint);
	setdata(&data, argv);
	hsh_loop(&data);
	freedata(&data);
	if (data.status < 0)
		return (255);
	return (data.status);
}