#include "main.h"

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

	status = _itoa(data->status);
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
		sum_b += (index->valuelen - index->varlen);
		index = index->next;
	}

	sum_b += sum_a;

	new_token = malloc(sizeof(char) * (sum_b + 1));
	new_token[sum_b] = '\0';

	new_token = replace_token(&head, token, new_token, sum_b);

	free(token);
	free(status);
	free_var_list(&head);

	return (new_token);
}
