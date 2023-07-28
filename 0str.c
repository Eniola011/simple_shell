#include "main.h"

/**
 * _strcat - combines two strings
 * @dest: pointer destination
 * @src: pointer source
 *
 * Return: return destination
 */
char *_strcat(char *dest, const char *src)
{
	int a;
	int b;

	for (a = 0; dest[a] != '\0'; a++)
		;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte, to the
 * buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * Return: the pointer to destination
 */
char *_strcpy(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if thesame
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
/**
 * _strchr - check string
 * @s: string
 * @c: character
 * Return: pointer
 */
char *_strchr(char *s, char c)
{
	unsigned int a = 0;

	for (; *(s + a) != '\0'; a++)
		if (*(s + a) == c)
			return (s + a);
	if (*(s + a) == c)
		return (s + a);
	return ('\0');
}
/**
 * _strspn - prefix substring.
 * @s: str
 * @acc: bytes
 * Return: bytes
 */
int _strspn(char *s, char *acc)
{
	int a, b, bull;

	for (a = 0; *(s + a) != '\0'; a++)
	{
		bull = 1;
		for (b = 0; *(acc + b) != '\0'; b++)
		{
			if (*(s + a) == *(acc + b))
			{
				bull = 0;
				break;
			}
		}
		if (bull == 1)
			break;
	}
	return (a);
}
