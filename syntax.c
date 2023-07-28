#include "main.h"

/**
 * repeat_chr - repeat characters
 * @chr: string
 * @i: index
 * Return: repeat strings
 */
int repeat_chr(char *chr, int i)
{
	if (*(chr - 1) == *chr)
		return (repeat_chr(chr - 1, i + 1));

	return (i);
}

/**
 * _error - checks syntax errors
 * @str: input string
 * @i: index
 * @tok: last char read
 * Return: index
 * errors
 */
int _error(char *str, int i, char tok)
{
	int n;

	n = 0;
	if (*str == '\0')
		return (0);

	if (*str == ' ' || *str == '\t')
		return (_error(str + 1, i + 1, tok));

	if (*str == ';')
		if (tok == '|' || tok == '&' || tok == ';')
			return (i);

	if (*str == '|')
	{
		if (tok == ';' || tok == '&')
			return (i);

		if (tok == '|')
		{
			n = repeat_chr(str, 0);
			if (n == 0 || n > 1)
				return (i);
		}
	}

	if (*str == '&')
	{
		if (tok == ';' || tok == '|')
			return (i);

		if (tok == '&')
		{
			n = repeat_chr(str, 0);
			if (n == 0 || n > 1)
				return (i);
		}
	}

	return (_error(str + 1, i + 1, *str));
}

/**
 * first_chr - finds first index char
 * @str: string
 * @i: index
 * Return: one
 */
int first_chr(char *str, int *i)
{

	for (*i = 0; str[*i]; *i += 1)
	{
		if (str[*i] == ' ' || str[*i] == '\t')
			continue;

		if (str[*i] == ';' || str[*i] == '|' || str[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntaxerror - prints found syntax error
 * @data: data
 * @str: string
 * @i: index
 * @bull: boolean
 * Return: no value
 */
void print_syntaxerror(list_sh *data, char *str, int i, int bull)
{
	char *text0, *text1, *text2, *err, *n;
	int len;

	if (str[i] == ';')
	{
		if (bull == 0)
			text0 = (str[i + 1] == ';' ? ";;" : ";");
		else
			text0 = (str[i - 1] == ';' ? ";;" : ";");
	}

	if (str[i] == '|')
		text0 = (str[i + 1] == '|' ? "||" : "|");

	if (str[i] == '&')
		text0 = (str[i + 1] == '&' ? "&&" : "&");

	text1 = ": Syntax error: \"";
	text2 = "\" unexpected\n";
	n = _itoa(data->count);
	len = _strlen(data->argv[0]) + _strlen(n);
	len += _strlen(text0) + _strlen(text1) + _strlen(text2) + 2;

	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(count);
		return;
	}
	_strcpy(err, data->argv[0]);
	_strcat(err, ": ");
	_strcat(err, count);
	_strcat(err, text1);
	_strcat(err, text0);
	_strcat(err, text2);
	_strcat(err, "\0");

	write(STDERR_FILENO, err, len);
	free(err);
	free(count);
}

/**
 * check_syntaxerror - finds syntax error
 * @data: data
 * @str: string
 * Return: zero
 */
int check_syntaxerror(list_sh *data, char *str)
{
	int a = 0;
	int cpy = 0;
	int i = 0;

	cpy = first_chr(str, &a);
	if (cpy == -1)
	{
		print_syntaxerror(data, str, a, 0);
		return (1);
	}

	i = _error(str + a, 0, *(str + a));
	if (i != 0)
	{
		print_syntaxerror(data, str, a + i, 1);
		return (1);
	}

	return (0);
}
