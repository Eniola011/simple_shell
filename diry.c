#include "main.h"

/**
 * shell_cd - change cd
 * @data: data
 * Return: success(1)
 */
int shell_cd(list_sh *data)
{
	char *diry;
	int home, home1, dash;

	diry = data->argc[1];

	if (diry != NULL)
	{
		home = _strcmp("$HOME", diry);
		home1 = _strcmp("~", diry);
		dash = _strcmp("--", diry);
	}

	if (diry == NULL || !home || !home1 || !dash)
	{
		cdhome(data);
		return (1);
	}

	if (_strcmp("-", diry) == 0)
	{
		cdprv(data);
		return (1);
	}

	if (_strcmp(".", diry) == 0 || _strcmp("..", diry) == 0)
	{
		cddot(data);
		return (1);
	}

	cdgo(data);

	return (1);
}
