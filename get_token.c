#include "main.h"

/**
 * get_token - gets token
 * @line: line of strings
 * @nread: strings read
 * Return: strings
 */
char **get_token(char *line, ssize_t nread)
{
	char *copy_line;
	char *sep = " \n";
	int ntoken = 0, index = 0;
	char *string, **strings;

	copy_line = malloc(sizeof(char) * nread);

	_strcpy(copy_line, line);

	string = strtok(line, sep);
	while (string != NULL)
	{
		ntoken++;
		string = strtok(NULL, sep);
	}
	ntoken++;

	strings = malloc(sizeof(char) * ntoken);

	string = strtok(copy_line, sep);
	while (string != NULL)
	{
		strings[index] = malloc(sizeof(char) * _strlen(string));
		_strcpy(strings[index], string);
		index++;
		string = strtok(NULL, sep);

	}

	strings[index] = NULL;
	return (strings);
	free(copy_line);
	free(strings);
}
