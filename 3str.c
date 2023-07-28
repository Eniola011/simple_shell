#include "main.h"

/**
 * get_len - length
 * @n: int
 * Return: len
 */
int get_len(int n)
{
	unsigned int n1;
	int len = 1;

	if (n < 0)
	{
		len++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		len++;
		n1 = n1 / 10;
	}

	return (len);
}

/**
 * _itoa - converts int to str
 * @n: int
 * Return: str.
 */
char *_itoa(int n)
{
	unsigned int n1;
	int len = get_len(n);
	char *buf;

	buf = malloc(sizeof(char) * (len + 1));
	if (buf == 0)
		return (NULL);

	*(buf + len) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buf[0] = '-';
	}
	else
	{
		n1 = n;
	}

	len--;
	do {
		*(buf + len) = (n1 % 10) + '0';
		n1 = n1 / 10;
		len--;
	}
	while (n1 > 0)
		;
	return (buf);
}

/**
 * _atoi - converts str to int
 * @s: str
 * Return: int
 */
int _atoi(char *s)
{
	unsigned int n = 0, size = 0, p = 0, q = 1, m = 1, a;

	while (*(s + n) != '\0')
	{
		if (size > 0 && (*(s + n) < '0' || *(s + n) > '9'))
			break;

		if (*(s + n) == '-')
			q *= -1;

		if ((*(s + n) >= '0') && (*(s + n) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		n++;
	}

	for (a = n - size; a < n; a++)
	{
		p = p + ((*(s + a) - 48) * m);
		m /= 10;
	}
	return (p * q);
}
