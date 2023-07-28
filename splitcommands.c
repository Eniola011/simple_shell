#include "main.h"

/**
 * dup_char - changes | and & for non-printed chars
 * @tok: string
 * @bull: boolean
 * Return: changed token
 */
char *dup_char(char *tok, int bull)
{
	int i;

	if (bull == 0)
	{
		for (i = 0; tok[i]; i++)
		{
			if (tok[i] == '|')
			{
				if (tok[i + 1] != '|')
					tok[i] = 16;
				else
					i++;
			}

			if (tok[i] == '&')
			{
				if (tok[i + 1] != '&')
					tok[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; tok[i]; i++)
		{
			tok[i] = (tok[i] == 16 ? '|' : tok[i]);
			tok[i] = (tok[i] == 12 ? '&' : tok[i]);
		}
	}
	return (tok);
}

/**
 * addanodes - adds separators and command lines in lists
 * @head1: head(separator list)
 * @head2: head(command lines list)
 * @strng: string
 * Return: no value
 */
void addanodes(sep_list **head1, cmd_list **head2, char *strng)
{
	int i;
	char *lineptr;

	strng = dup_char(strng, 0);

	for (i = 0; strng[i]; i++)
	{
		if (strng[i] == ';')
			add_node(head1, strng[i]);

		if (strng[i] == '|' || strng[i] == '&')
		{
			add_node(head1, strng[i]);
			i++;
		}
	}

	lineptr = _strtok(strng, ";|&");
	do {
		lineptr = dup_char(lineptr, 1);
		add_node(head2, lineptr);
		lineptr = _strtok(NULL, ";|&");
	} while (lineptr != NULL);

}

/**
 * _next - move to next command
 * @list1: separator list
 * @list2: command line list
 * @data: data
 * Return: no return
 */
void _next(sep_list **list1, cmd_list **list2, list_sh *data)
{
	int separator;
	sep_list *s1;
	cmd_list *s2;

	separator = 1;
	s1 = *list1;
	s2 = *list2;

	while (s1 != NULL && separator)
	{
		if (data->status == 0)
		{
			if (s1->sep == '&' || s1->sep == ';')
				separator = 0;
			if (s1->sep == '|')
				s2 = s2->next, s1 = s1->next;
		}
		else
		{
			if (s1->sep == '|' || s1->sep == ';')
				separator = 0;
			if (s1->sep == '&')
				s2 = s2->next, s1 = s1->next;
		}
		if (s1 != NULL && !separator)
			s1 = s1->next;
	}

	*list1 = s1;
	*list2 = s2;
}

/**
 * split_cmds - splits command lines using | and &
 * @data: data
 * @str: string
 * Return: continue(1), exit(0)
 */
int split_cmds(list_sh *data, char *str)
{

	sep_list *head1, *list1;
	cmd_list *head2, *list2;
	int nread;

	head1 = NULL;
	head2 = NULL;

	addanodes(&head1, &head2, str);

	list1 = head1;
	list2 = head2;

	while (list2 != NULL)
	{
		data->input = list2->lineptr;
		data->argc = splitline(data->input);
		nread = exec(data);
		free(data->argc);

		if (nread == 0)
			break;

		_next(&list1, &list2, data);

		if (list2 != NULL)
			list2 = list2->next;
	}

	free_seplist(&head1);
	free_linelist(&head2);

	if (nread == 0)
		return (0);
	return (1);
}

/**
 * splitline - tokenize string
 * @strng: string.
 * Return: string
 */
char **splitline(char *strng)
{
	size_t buffy;
	size_t i;
	char **toks;
	char *tok;

	buffy = TOKEN_BUFFSIZE;
	toks = malloc(sizeof(char *) * (buffy));
	if (toks == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	tok = _strtok(strng, TOKEN_DELIM);
	toks[0] = tok;

	for (i = 1; tok != NULL; i++)
	{
		if (i == buffy)
		{
			buffy += TOKEN_BUFFSIZE;
			toks = _reallocdp(toks, i, sizeof(char *) * buffy);
			if (toks == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		tok = _strtok(NULL, TOKEN_DELIM);
		toks[i] = tok;
	}

	return (toks);
}
