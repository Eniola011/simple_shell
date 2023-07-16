#include "main.h"

/**
 * _strstr - finds the first occurrence of the substring.
 * @haystack: entire string.
 * @needle: substring.
 * Return: pointer to the beginning or NULL
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *Begin = haystack;
		char *pattern = needle;

		while (*haystack && *pattern && *haystack == *pattern)
		{
			haystack++;
			pattern++;
		}
		if (!*pattern)
		{
			return (Begin);
		}
		haystack = Begin + 1;
	}
	return (0);
}
