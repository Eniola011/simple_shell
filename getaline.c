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

/**
 * _getline - get line
 * @line: input
 * @n: size of input
 * @strm: line read
 * Return: value
 */
ssize_t _getline(char **line, size_t *n, FILE *strm)
{
	int indx;
	char *buf, chr = 'z';
	ssize_t value;
	static ssize_t argmt;

	if (argmt == 0)
		fflush(strm);
	else
		return (-1);

	argmt = 0, buf = malloc(sizeof(char) * BUFF);
	if (buf == 0)
		return (-1);
	while (chr != '\n')
	{
		indx = read(STDIN_FILENO, &chr, 1);
		if (indx == -1 || (indx == 0 && argmt == 0))
		{
			free(buf);
			return (-1);
		}
		if (indx == 0 && argmt != 0)
		{
			argmt++;
			break;
		}
		if (argmt >= BUFF)
			buf = _realloc(buf, argmt, argmt + 1);

		buf[argmt] = chr, argmt++;
	}
	buf[argmt] = '\0';
	_line(line, n, buf, argmt);
	value = argmt;
	if (indx != 0)
		argmt = 0;

	return (value);
}
