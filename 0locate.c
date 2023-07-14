#include "main.h"

/**
 * find_path - checks for path
 * @pathenviron: path token
 * @progrm: the string
 * Return: path.
 */
char *find_path(char **pathenviron, char *progrm)
{
	int index = 1;
	char *copy;

	copy = _stralloc(3, pathenviron[0], "/", progrm);
	while (access(copy, X_OK) == 1 && pathenviron[index] != NULL)
	{
		free(copy);
		copy = _stralloc(3, pathenviron[index], "/", progrm);
		index++;
	}
	if (pathenviron[index] == NULL)
	{
		return (NULL);
	}
	else
	{
		return (copy);
	}
}
