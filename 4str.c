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
		cptr1[index] = cptr[index];
}

/**
 * _realloc - reallocate memory
 * @ptr: old pointer
 * @oldsize: old size
 * @newsize: new size
 * Return: new pointer
 */
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize)
{
	void *new;

	if (ptr == NULL)
		return (malloc(newsize));

	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (newsize == oldsize)
		return (ptr);

	new = malloc(newsize);
	if (new == NULL)
		return (NULL);

	if (newsize < oldsize)
		_memcpy(new, ptr, newsize);
	else
		_memcpy(new, ptr, oldsize);

	free(ptr);
	return (new);
}

/**
 * _reallocdp - reallocate a mem block of a double pointer.
 * @ptr: double pointer
 * @oldsize: size
 * @newsize: new size
 *
 * Return: ptr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int oldsize, unsigned int newsize)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * newsize));

	if (newsize == oldsize)
		return (ptr);

	newptr = malloc(sizeof(char *) * newsize);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < oldsize; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
