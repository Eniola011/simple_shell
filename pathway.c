#include "main.h"
/**
 * find_path - locates path
 * @cmd: command
 * Return: full path
 */
char *find_path(char *cmd)
{
	char *pathway, *pathway2, *pathtok, *diry;
	int cmdlen, dirlen;
	struct stat test_file;

	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (stat(cmd, &test_file) == 0)
		{
			return (cmd);
		}
	}
	pathway = getenv("PATH");
	if (pathway)
	{
		pathway2 = _strdup(pathway);
		cmdlen = _strlen(cmd);
		pathtok = strtok(pathway2, ":");
		while (pathtok != NULL)
		{
			dirlen = _strlen(pathtok);
			diry = malloc(dirlen + cmdlen + 2);
			_strcpy(diry, pathtok), _strcat(diry, "/");
			_strcat(diry, cmd), _strcat(diry, "\0");

			if (stat(diry, &test_file) == 0)
			{
				free(pathway2);
				return (diry);
			}
			free(diry);
			pathtok = strtok(NULL, ":");
		}
		free(pathway2);

		return (NULL);
	}
	return (NULL);
}
