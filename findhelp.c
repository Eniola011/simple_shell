#include "main.h"

/**
 * find_help - gets help in builtin
 * @data: data for argc and inputs
 * Return: 0
*/
int find_help(list_sh *data)
{

	if (data->argc[1] == 0)
		help_general();
	else if (_strcmp(data->argc[1], "setenv") == 0)
		help_setenv();
	else if (_strcmp(data->argc[1], "env") == 0)
		help_env();
	else if (_strcmp(data->argc[1], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(data->argc[1], "help") == 0)
		_help();
	else if (_strcmp(data->argc[1], "exit") == 0)
		help_exit();
	else if (_strcmp(data->argc[1], "cd") == 0)
		help_cd();
	else if (_strcmp(data->argc[1], "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, data->argc[0],
		      _strlen(data->argc[0]));

	data->status = 0;

	return (1);
}
