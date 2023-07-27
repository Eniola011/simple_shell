#include "main.h"

/**
 * exec - checks builtin commands
 * @data: data
 * Return: success(1)
 */
int exec(list_sh *data)
{
	int (*builts)(list_sh *data);

	if (data->argc[0] == NULL)
		return (1);

	builts = find_builtin(data->argc[0]);

	if (builts != NULL)
		return (builts(data));

	return (exec_cmmd(data));
}
