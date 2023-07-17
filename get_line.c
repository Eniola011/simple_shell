#include "main.h"

/**
 * get_line - determine number of tokens.
 * @strng: inputted string
 * @delim: separates string
 * Return: number of strings.
 */
int get_line(char *strng, char *delim)
{
	int a = 0;
	int b = 0;
	int c = 0;

	while (delim[a])
	{
		while (strng[b])
		{
			if (strng[b++] == delim[a] && strng[b] != delim[a])
			{
				c++;
			}
		}
		b = 0;
		a++;
	}
	return (c);
}
