#include "main.h"

/**
 * add_var_node - add var at the end
 * @h: beginning of list
 * @n: var len
 * @v: value of var
 * @len: value len
 * Return: h
 */
varb_list *add_var_node(varb_list **h, int n, char *v, int len)
{
	varb_list *newptr, *cpy;

	newptr = malloc(sizeof(varb_list));
	if (newptr == NULL)
		return (NULL);

	newptr->varlen = n;
	newptr->value = v;
	newptr->valuelen = len;

	newptr->next = NULL;
	cpy = *h;

	if (cpy == NULL)
	{
		*h = newptr;
	}
	else
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = newptr;
	}

	return (*h);
}

/**
 * free_var_list - free varb_list
 * @h: beginning of list
 * Return: no value
 */
void free_var_list(varb_list **h)
{
	varb_list *cpy;
	varb_list *current;

	if (h != NULL)
	{
		current = *h;
		while ((cpy = current) != NULL)
		{
			current = current->next;
			free(cpy);
		}
		*h = NULL;
	}
}
