#include "main.h"

/**
 * read_a_line - reads inputted strings
 * @nread: num of read strings
 * Return: buff
 */
char *read_a_line(ssize_t *nread)
{
	char *buff = NULL;
	size_t len = 0;

	*nread = getline(&buff, &len, stdin);
	return (buff);
}
