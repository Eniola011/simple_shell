#include "main.h"

/**
 * read_a_line - reads inputted strings
 * @nread: num of read strings
 * Return: buff
 */
char *read_a_line(int *nread)
{
	char *strng = NULL;
	size_t len = 0;

	*nread = getline(&strng, &len, stdin);

	return (strng);
}
