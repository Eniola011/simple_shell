#include "main.h"

/**
 * find_error - checks for errors
 * @data: data
 * @errval: error value
 * Return: error value
 */
int find_error(list_sh *data, int errval)
{
	char *err;

	switch (errval)
	{
	case -1:
		err = env_error(data);
		break;
	case 126:
		err = error_126(data);
		break;
	case 127:
		err = not_found(data);
		break;
	case 2:
		if (_strcmp("exit", data->argc[0]) == 0)
			err = exit_shell(data);
		else if (_strcmp("cd", data->argc[0]) == 0)
			err = error_cd(data);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	data->status = errval;

	return (errval);
}
