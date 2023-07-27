#include "main.h"

/**
 * main - checks all codes
 *
 * Return: status code
 */
int main(void)
{
	char *line, **string;
	ssize_t nread;
	int status = 0;

	while (1)
	{
		write(2, ":) ", 3);

		line = read_a_line(&nread);

		if (nread == -1)
		{
			write(2, "Exiting shell....\n", 18);
			exit(1);
		}

		string = get_token(line, nread);

		if (string[0] != NULL)
		{
			status = exec_cmd(string);
		}

		free(string);
		free(line);
	}

	return (status);
}
