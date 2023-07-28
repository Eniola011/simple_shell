#include "main.h"

/**
 * _help - help
 * Return: no value
 */
void _help(void)
{
	char *asst = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "\tDisplay builtin commands.\n ";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "Displays builtin commands.\n";
	write(STDOUT_FILENO, asst, _strlen(asst));
}

/**
 * help_alias - help
 * Return: no value
 */
void help_alias(void)
{
	char *asst = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "\tDisplay aliases.\n ";
	write(STDOUT_FILENO, asst, _strlen(asst));
}

/**
 * help_cd - help
 * Return: no value
 */
void help_cd(void)
{
	char *asst = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "\tChange working directory.\n ";
	write(STDOUT_FILENO, asst, _strlen(asst));
}
