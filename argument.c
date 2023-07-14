#include "main.h"

/**
 * check_argmt - check access for argument inputted
 * @argumt: arguments inputted
 * Return: success(1), fail(0).
 */
unsigned int check_argmt(char *argumt)
{
	if (access(argumt, X_OK) == 1)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
