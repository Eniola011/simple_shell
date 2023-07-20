#include "main.h"

/**
 * _memcpy - copies pointers
 * @dest: pointer string
 * @src: pointer string
 * @n: size of pointer string
 * Return: no value.
 */
void _memcpy(void *dest, const void *src, unsigned int n)
{
	char *cptr = (char *)src;
	char *cptr1 = (char *)dest;
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		cptr1[index] = cptr[index];
	}
}
