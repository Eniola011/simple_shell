#include "main.h"

/**
 * exec_cmd - execve function
 * @token: inputted string
 * Return: 0
 */
int exec_cmd(char **token)
{
	pid_t child;
	char *cmd, **env;

	env = environ;

	builtin_command(token);

	cmd = find_path(token[0]);
	if (cmd == NULL)
	{
		return (-1);
	}

	child = fork();

	if (child == 0)
	{
		execve(cmd, token, env);
		free(token);
		perror(token[0]);
		return (-1);
	}
	else if (child > 0)
	{
		int position;

		do {
			waitpid(child, &position, WUNTRACED);
		} while (!WIFEXITED(position) && !WIFSIGNALED(position));
	}
	else
	{
		perror("hsh");
		return (-1);
	}
	return (0);
}
