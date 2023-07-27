#include "main.h"

/**
 * exit_sh - leaves shell
 * @data: data
 * Return: success(0)
 */
int exit_sh(list_sh *data)
{
	unsigned int stats;
	int digit;
	int str_length;
	int _num;

	if (data->argc[1] != NULL)
	{
		stats = _atoi(data->argc[1]);
		digit = _isdigit(data->argc[1]);
		str_length = _strlen(data->argc[1]);
		_num = stats > (unsigned int)INT_MAX;
		if (!digit || str_length > 10 || _num)
		{
			find_error(data, 2);
			data->status = 2;
			return (1);
		}
		data->status = (stats % 256);
	}

	return (0);
}
