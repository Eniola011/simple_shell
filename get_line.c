#include "main.h"

/**
 * get_line - determine number of tokens.
 * @strng: inputted string
 * @sep: separates string/delimiter
 * Return: number of strings.
 */
int get_line(char *strng, char *sep)
{
	int a = 0;
	int b = 0;
	int c = 0;

	while (sep[a])
	{
		while (strng[b])
		{
			if (strng[b++] == sep[a] && strng[b] != sep[a])
			{
				c++;
			}
		}
		b = 0;
		a++;
	}
	return (c);
}
