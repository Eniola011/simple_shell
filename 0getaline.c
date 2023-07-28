#include "main.h"

/**
 * _line - gets line for stream
 * @line: input
 * @n: size of line
 * @buff: buffer
 * @i: size of buff
 * Return: no value
 */
void _line(char **line, size_t *n, char *buff, size_t i)
{

	if (*line == NULL)
	{
		if  (i > BUFF)
			*n = i;

		else
			*n = BUFF;
		*line = buff;
	}
	else if (*n < i)
	{
		if (i > BUFF)
			*n = i;
		else
			*n = BUFF;
		*line = buff;
	}
	else
	{
		_strcpy(*line, buff);
		free(buff);
	}
}