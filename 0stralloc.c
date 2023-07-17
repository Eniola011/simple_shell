#include "main.h"
/**
 * _stralloc - link string
 * @counter: string
 * Return: linked strings
 */
char *_stralloc(int counter, ...)
{
	va_list valist;
	char *arg_copy;
	char *arg_ptr;
	char *result;
	int strng_length;
	int arg_length;

	va_start(valist, counter);
	arg_copy = va_arg(valist, char *), counter--;
	arg_length = _strlen(arg_copy);
	result = malloc(sizeof(char) * arg_length + 1);
	if (result == NULL)
	{
		perror("Segmenation Fault: ");
		exit(EXIT_FAILURE);
	}
	_strcpy(result, arg_copy);
	while (counter != 0)
	{
		arg_copy = va_arg(valist, char *), counter--;
		strng_length = _strlen(result);
		arg_length = _strlen(arg_copy);
		arg_ptr = malloc(sizeof(char) * (strng_length + arg_length) + 1);
		if (arg_ptr == NULL)
		{
			perror("Segmenation Fault: ");
			exit(EXIT_FAILURE);
		}

		if (result != NULL)
		{
			_strcpy(arg_ptr, result);
			free(result);
		}
		_strcat(arg_ptr, arg_copy);
		result = arg_ptr;
	}
	va_end(valist);

	return (result);
}
