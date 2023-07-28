#include "main.h"

/**
 * rev_string - reverse a string.
 * @s: string
 * Return: no value
 */
void rev_string(char *s)
{
	int num = 0, a, b;
	char *strng, copy;

	while (num >= 0)
	{
		if (s[num] == '\0')
			break;
		num++;
	}
	strng = s;

	for (a = 0; a < (num - 1); a++)
	{
		for (b = a + 1; b > 0; b--)
		{
			copy = *(strng + b);
			*(strng + b) = *(strng + (b - 1));
			*(strng + (b - 1)) = copy;
		}
	}
}
