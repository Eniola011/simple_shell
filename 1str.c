#include "main.h"

/**
 * _strdup - duplicates strings
 * @s: pointer string
 * Return: duplicated string
 */
char *_strdup(const char *s)
{
	char *n;
	size_t len;

	len = _strlen(s);
	n = malloc(sizeof(char) * (len + 1));
	if (n == NULL)
		return (NULL);
	_memcpy(n, s, len + 1);
	return (n);
}

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of a string.
 */
int _strlen(const char *s)
{
	int num;

	for (num = 0; s[num] != 0; num++)
	{
	}
	return (num);
}

/**
 * cmpchr - compare string
 * @strng: input
 * @delim: separator
 * Return: zero
 */
int cmpchr(char strng[], const char *delim)
{
	unsigned int a, b, c;

	for (a = 0, c = 0; strng[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (strng[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * _strtok - splits string
 * @str: input
 * @delim: delimiter.
 * Return: str.
 */
char *_strtok(char str[], const char *delim)
{
	static char *strng, *endstr;
	char *startstr;
	unsigned int i, bull;

	if (str != NULL)
	{
		if (cmpchr(str, delim))
			return (NULL);
		strng = str;
		i = _strlen(str);
		endstr = &str[i];
	}
	startstr = strng;
	if (startstr == endstr)
		return (NULL);

	for (bull = 0; *strng; strng++)
	{
		if (strng != startstr)
			if (*strng && *(strng - 1) == '\0')
				break;

		for (i = 0; delim[i]; i++)
		{
			if (*strng == delim[i])
			{
				*strng = '\0';
				if (strng == startstr)
					startstr++;
				break;
			}
		}
		if (bull == 0 && *strng)
			bull = 1;
	}
	if (bull == 0)
		return (NULL);
	return (startstr);
}

/**
 * _isdigit - is string a digit
 * @s: input
 * Return: one
 */
int _isdigit(const char *s)
{
	unsigned int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] < 48 || s[a] > 57)
			return (0);
	}

	return (1);
}
