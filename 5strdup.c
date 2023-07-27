#include "main.h"

/**
 * _strdup - duplicates strings
 * @s: pointer string
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	char *n;
	size_t length;

	length = _strlen(s);
	n = malloc(sizeof(char) * (length + 1));
	if (n == NULL)
	{
		return (NULL);
	}
	_memcpy(n, s, length + 1);
	return (n);
	free(n);
}
