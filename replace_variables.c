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
				add_var_node(h, 2, sts, last), i++;
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

/**
 * replace_token - replaces string
 * @h: beginning of the linked list
 * @tok: string
 * @new_tok: new string
 * @sum_b: length
 * Return: new str
 */
char *replace_token(varb_list **h, char *tok, char *new_tok, int sum_b)
{
	varb_list *index;
	int a, b, c;

	index = *h;
	for (b = a = 0; a < sum_b; a++)
	{
		if (tok[b] == '$')
		{
			if (!(index->varlen) && !(index->valuelen))
			{
				new_tok[a] = tok[b];
				b++;
			}
			else if (index->varlen && !(index->valuelen))
			{
				for (c = 0; c < index->varlen; c++)
					b++;
				a--;
			}
			else
			{
				for (c = 0; c < index->valuelen; c++)
				{
					new_tok[a] = index->value[c];
					a++;
				}
				b += (index->varlen);
				a--;
			}
			index = index->next;
		}
		else
		{
			new_tok[a] = tok[b];
			b++;
		}
	}

	return (new_tok);
}

/**
 * replace_var - replace string into variable
 * @token: string
 * @data: data
 * Return: token
 */
char *replace_var(char *token, list_sh *data)
{
	varb_list *head, *index;
	char *status, *new_token;
	int sum_a, sum_b;

	status = aux_itoa(data->status);
	head = NULL;

	sum_a = find_varb(&head, token, status, data);

	if (head == NULL)
	{
		free(status);
		return (token);
	}

	index = head;
	sum_b = 0;

	while (index != NULL)
	{
		sum_b += (index->valuelen - indx->varlen);
		index = index->next;
	}

	sum_b += sum_a;

	new_token = malloc(sizeof(char) * (sum_b + 1));
	new_token[sum_b] = '\0';

	new_token = replaced_input(&head, token, new_token, sum_b);

	free(token);
	free(status);
	free_var_list(&head);

	return (new_token);
}
