#include "main.h"

/**
 * get_path - get path for the program
 * @progrm: token inputted
 *
 * Return: complete path
 */
char *get_path(char *progrm)
{
	char *copy;
	char *envcopy;
	char **argcopy;

	copy = env_key("PATH");
	envcopy = _stralloc(1, copy);
	argcopy = _strtok(&envcopy, ":");
	copy = find_path(argcopy, progrm);

	free(envcopy);
	free(argcopy);

	return (copy);
}
