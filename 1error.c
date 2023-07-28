#include "main.h"

/**
 * env_error - error msg
 * @data: data
 * Return: error msg.
 */
char *env_error(list_sh *data)
{
	int len;
	char *err;
	char *strng;
	char *txt;

	strng = _itoa(data->count);
	txt = ": inability to add/remove from environment\n";
	len = _strlen(data->argv[0]) + _strlen(strng);
	len += _strlen(data->argc[0]) + _strlen(txt) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(strng);
		return (NULL);
	}

	_strcpy(err, data->argv[0]);
	_strcat(err, ": ");
	_strcat(err, strng);
	_strcat(err, ": ");
	_strcat(err, data->argc[0]);
	_strcat(err, txt);
	_strcat(err, "\0");
	free(strng);

	return (err);
}

/**
 * error_126 - error msg
 * @data: data
 * Return: error
 */
char *error_126(list_sh *data)
{
	int len;
	char *strng;
	char *err;

	strng = _itoa(data->count);
	len = _strlen(data->argv[0]) + _strlen(strng);
	len += _strlen(data->argc[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(strng);
		return (NULL);
	}
	_strcpy(err, data->argv[0]);
	_strcat(err, ": ");
	_strcat(err, strng);
	_strcat(err, ": ");
	_strcat(err, data->argc[0]);
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(strng);
	return (err);
}
