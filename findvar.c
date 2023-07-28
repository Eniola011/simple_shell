#include "main.h"

/**
 * find_varb - is variable inputted $$ or $?
 * @h: beginning of the linked list
 * @str: string
 * @sts: status code
 * @data: data structure
 * Return: no return
 */
int find_varb(varb_list **h, char *str, char *sts, list_sh *data)
{
	int i, first, last;

	first = _strlen(sts);
	last = _strlen(data->pidd);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				add_var_node(h, 2, sts, first), i++;
			else if (str[i + 1] == '$')
				add_var_node(h, 2, data->pidd, last), i++;
			else if (str[i + 1] == '\n')
				add_var_node(h, 0, NULL, 0);
			else if (str[i + 1] == '\0')
				add_var_node(h, 0, NULL, 0);
			else if (str[i + 1] == ' ')
				add_var_node(h, 0, NULL, 0);
			else if (str[i + 1] == '\t')
				add_var_node(h, 0, NULL, 0);
			else if (str[i + 1] == ';')
				add_var_node(h, 0, NULL, 0);
			else
				find_env(h, str + i, data);
		}
	}

	return (i);
}
