#include "main.h"

/**
 * find_builtin - builtin functions
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*find_builtin(char *cmd))(list_sh *)
{
	built_in builts[] = {
		{ "env", _env },
		{ "exit", exit_sh },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", shell_cd },
		{ "help", find_help },
		{ NULL, NULL }
	};
	int indx;

	for (indx = 0; builtin[indx].tag; indx++)
	{
		if (_strcmp(builtin[indx].tag, cmd) == 0)
			break;
	}

	return (builtin[indx].funt);
}
