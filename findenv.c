#include "main.h"

/**
 * find_env - is var typed an environment var
 * @h: head of linked list
 * @str: string
 * @data: data structure
 * Return: no return
 */
void find_env(varb_list **h, char *str, list_sh *data)
{
	int r, ch, j, vall;
	char **_envp;

	_envp = data->_env;
	for (r = 0; _envp[r]; r++)
	{
		for (j = 1, ch = 0; _envp[r][ch]; ch++)
		{
			if (_envp[r][ch] == '=')
			{
				vall = _strlen(_envp[r] + ch + 1);
				add_var_node(h, j, _envp[r] + ch + 1, vall);
				return;
			}

			if (str[j] == _envp[r][ch])
				j++;
			else
				break;
		}
	}

	for (j = 0; str[j]; j++)
	{
		if (str[j] == ' ' || str[j] == '\t' || str[j] == ';' || str[j] == '\n')
			break;
	}

	add_var_node(h, j, NULL, 0);
}