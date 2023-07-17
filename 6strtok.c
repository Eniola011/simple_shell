#include "main.h"

/**
 * _strtok - gets strings
 * @buf: strings inputted
 * @delimiter: separator
 * Return: array of strings
 */
char **_strtok(char **buf, char *delimiter)
{
	int index;
	char *token;
	char **arg_vector;
	int token_copy;

	token_copy = get_line(*buf, delimiter);

	token = strtok(*buf, delimiter);
	if (token == NULL)
	{
		perror("Please pass a command: ");
		exit(0);
	}

	arg_vector = malloc(sizeof(char *) * (token_copy + 1));
	if (arg_vector == NULL)
	{
		perror("Mem Allocation Error: ");
		exit(2);
	}

	index = 1, arg_vector[0] = token;
	while (token != NULL)
	{
		token = strtok(NULL, delimiter);
	}
	if (token != NULL)
	{
		arg_vector[index] = token;
		index++;
	}

	arg_vector[index] = NULL;
	return (arg_vector);
}
