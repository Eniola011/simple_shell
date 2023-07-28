#include "main.h"

/**
 * help_env - assist
 * Return: no value
 */
void help_env(void)
{
	char *asst = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "Print the env of the shell.\n";
	write(STDOUT_FILENO, asst, _strlen(asst));

}

/**
 * help_setenv - assist
 * Return: no value
 */
void help_setenv(void)
{

	char *asst = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "int replace)\n\t";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "Add a new def to the env\n";
	write(STDOUT_FILENO, asst, _strlen(asst));
}

/**
 * help_unsetenv - assist
 * Return: no value
 */
void help_unsetenv(void)
{
	char *asst = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, asst, _strlen(asst));
}

/**
 * help_general - assist
 * Return: no value
 */
void help_general(void)
{
	char *asst = ":)$ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "These are defined commands,.type 'asst' to see more on the list";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "Type 'asst name' to find out more about the function 'assist'.\n\n ";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "[argc]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "unsetenv [variable]\n";
	write(STDOUT_FILENO, asst, _strlen(asst));
}

/**
 * help_exit - assist
 * Return: no value
 */
void help_exit(void)
{
	char *asst = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "leave shell with a status of N. If N is not there, then leave";
	write(STDOUT_FILENO, asst, _strlen(asst));
	asst = "what is the last command executed\n";
	write(STDOUT_FILENO, asst, _strlen(asst));
}
