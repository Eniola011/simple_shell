#include "main.h"

/**
 * env_key - key value of environ
 * @kii: key
 *
 * Return: environ.
 */
char *env_key(char **kii)
{
	int index = 0;
	char *copy;

	while (_strstr(environ[index], kii) == NULL && environ[index] != NULL)
	{
		index++;
	}
	if (environ[index] == NULL)
	{
		return (NULL);
	}
	copy = _strstr(environ[index], "=");
	copy++;
	return (copy);
}
