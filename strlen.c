#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of a string.
 */
int _strlen(char *s)
{
	int num = 0;

	while (s[num] != 0)
	{
		num++;
	}
	return (num);
}
