#include "main.h"

/**
 * execmd - execute commands
 * @progrm: string
 * @args: arguments
 * Returns: no value
 */
void execmd(char *progrm, char **args)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("fork failed...");
		exit(EXIT_FAILURE);
	}

	if (child == 0)

	if (execve(progrm, args, NULL) == -1)
	{
		perror("Error processing..");
		exit(EXIT_FAILURE);
	}
}
