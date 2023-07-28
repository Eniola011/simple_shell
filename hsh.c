#include "main.h"

/**
 * _comment - removes comments
 * @token: string
 * Return: string without comment
 */
char *_comment(char *token)
{
	int i, dest;

	dest = 0;
	for (i = 0; token[i]; i++)
	{
		if (token[i] == '#')
		{
			if (i == 0)
			{
				free(token);
				return (NULL);
			}

			if (token[i - 1] == ' ' || token[i - 1] == '\t' || token[i - 1] == ';')
				dest = i;
		}
	}

	if (dest != 0)
	{
		token = _realloc(token, i, dest + 1);
		token[dest] = '\0';
	}

	return (token);
}

/**
 * hsh_loop - Loop of shell
 * @data: data
 * Return: no value
 */
void hsh_loop(list_sh *data)
{
	int path, nread;
	char *tok;

	path = 1;
	while (path == 1)
	{
		write(STDIN_FILENO, ":)$ ", 4);
		tok = read_a_line(&nread);
		if (nread != -1)
		{
			tok = _comment(tok);
			if (tok == NULL)
				continue;

			if (check_syntaxerror(data, tok) == 1)
			{
				data->status = 2;
				free(tok);
				continue;
			}
			tok = replace_var(tok, data);
			path = split_cmds(data, tok);
			data->count += 1;
			free(tok);
		}
		else
		{
			path = 0;
			free(tok);
		}
	}
}
