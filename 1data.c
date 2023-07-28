#include "main.h"

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
	data->pidd = _itoa(getpid());
}
