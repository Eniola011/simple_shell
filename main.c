#include "main.h"

/**
 * main - checks code
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: success(0).
 */
int main(int argc, char **argv)
{
	list_sh data;
	(void) argc;

	signal(SIGINT, find_sigint);
	setdata(&data, argv);
	hsh_loop(&data);
	freedata(&data);
	if (data.status < 0)
		return (255);

	return (data.status);
}