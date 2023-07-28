#include "main.h"

/**
 * strcat_cd - join message
 * @data: data
 * @txt: msg
 * @err: msg
 * @str: str
 * Return: error
 */
char *strcat_cd(list_sh *data, char *txt, char *err, char *str)
{
	char *ill_flag;

	_strcpy(err, data->argv[0]);
	_strcat(err, ": ");
	_strcat(err, str);
	_strcat(err, ": ");
	_strcat(err, data->argc[0]);
	_strcat(err, txt);
	if (data->argc[1][0] == '-')
	{
		ill_flag = malloc(3);
		ill_flag[0] = '-';
		ill_flag[1] = data->argc[1][1];
		ill_flag[2] = '\0';
		_strcat(err, ill_flag);
		free(ill_flag);
	}
	else
	{
		_strcat(err, data->argc[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * error_cd - error message
 * @data: data
 * Return: error
 */
char *error_cd(list_sh *data)
{
	int len, _len;
	char *err, *str, *txt;

	str = _itoa(data->count);
	if (data->argc[1][0] == '-')
	{
		txt = ": Illegal option ";
		_len = 2;
	}
	else
	{
		txt = ": can't cd to ";
		_len = _strlen(data->argc[1]);
	}

	len = _strlen(data->argv[0]) + _strlen(data->argc[0]);
	len += _strlen(str) + _strlen(txt) + _len + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(str);
		return (NULL);
	}

	err = strcat_cd(data, txt, err, str);

	free(str);

	return (err);
}

/**
 * not_found - not found
 * @data: data
 * Return: error
 */
char *not_found(list_sh *data)
{
	int len;
	char *err;
	char *str;

	str = _itoa(data->count);
	len = _strlen(data->argv[0]) + _strlen(str);
	len += _strlen(data->argc[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(str);
		return (NULL);
	}
	_strcpy(err, data->argv[0]);
	_strcat(err, ": ");
	_strcat(err, str);
	_strcat(err, ": ");
	_strcat(err, data->argc[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(str);
	return (err);
}

/**
 * exit_shell - exit shell
 * @data: data
 * Return: error
 */
char *exit_shell(list_sh *data)
{
	int len;
	char *err;
	char *str;

	str = _itoa(data->count);
	len = _strlen(data->argv[0]) + _strlen(str);
	len += _strlen(data->argc[0]) + _strlen(data->argc[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(str);
		return (NULL);
	}
	_strcpy(err, data->argv[0]);
	_strcat(err, ": ");
	_strcat(err, str);
	_strcat(err, ": ");
	_strcat(err, data->argc[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, data->argc[1]);
	_strcat(err, "\n\0");
	free(str);

	return (err);
}
