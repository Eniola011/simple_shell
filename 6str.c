#include "main.h"

/**
 * add_node - add a separator to end of node
 * @h: beginning of linked list.
 * @s: separator
 * Return: h
 */
sep_list *add_node(sep_list **h, char s)
{
	sep_list *newnode, *cpy;

	newnode = malloc(sizeof(sep_list));
	if (newnode == NULL)
		return (NULL);

	newnode->sep = s;
	newnode->next = NULL;
	cpy = *h;

	if (cpy == NULL)
	{
		*h = newnode;
	}
	else
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = newnode;
	}

	return (*h);
}

/**
 * free_seplist - free sep_list
 * @h: beginning linked list.
 * Return: no value
 */
void free_seplist(sep_list **h)
{
	sep_list *cpy;
	sep_list *current;

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

/**
 * add_line - add  cmd line at the end
 * @h: beginning of linked list.
 * @n: cmd line.
 * Return: h
 */
cmd_list *add_line(cmd_list **h, char *n)
{
	cmd_list *newnode, *cpy;

	newnode = malloc(sizeof(cmd_list));
	if (newnode == NULL)
		return (NULL);

	newnode->lineptr = n;
	newnode->next = NULL;
	cpy = *h;

	if (cpy == NULL)
	{
		*h = newnode;
	}
	else
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = newnode;
	}

	return (*h);
}

/**
 * free_linelist - free cmd_list
 * @h: beginning of linked list
 * Return: no value
 */
void free_linelist(cmd_list **h)
{
	cmd_list *cpy;
	cmd_list *current;

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
