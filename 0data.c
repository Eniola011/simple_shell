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