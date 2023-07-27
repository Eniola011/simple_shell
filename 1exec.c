#include "main.h"

/**
 * isit_cdir - is it current directory
 * @p: char pointer
 * @a: int pointer
 * Return: zero
 */
int isit_cdir(char *p, int *a)
{
	if (p[*a] == ':')
		return (1);

	while (p[*a] != ':' && p[*a])
	{
		*a += 1;
	}

	if (p[*a])
		*a += 1;

	return (0);
}

/**
 * _locate - find command
 * @cmd: command
 * @env: env var
 * Return: location of the command.
 */
char *_locate(char *cmd, char **env)
{
	char *path, *cpy_path, *pathtok, *dir;
	int dirlen, cmdlen, indx;
	struct stat sts;

	path = _getenv("PATH", env);
	if (path)
	{
		cpy_path = _strdup(path);
		cmdlen = _strlen(cmd);
		pathtok = _strtok(cpy_path, ":");
		indx = 0;
		while (pathtok != NULL)
		{
			if (isit_cdir(path, &indx))
				if (stat(cmd, &sts) == 0)
					return (cmd);
			dirlen = _strlen(pathtok);
			dir = malloc(dirlen + cmdlen + 2);
			_strcpy(dir, pathtok);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &sts) == 0)
			{
				free(cpy_path);
				return (dir);
			}
			free(dir);
			pathtok = _strtok(NULL, ":");
		}
		free(cpy_path);
		if (stat(cmd, &sts) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &sts) == 0)
			return (cmd);
	return (NULL);
}

/**
 * isit_executable - check an executable
 * @data: data
 * Return: zero
 */
int isit_executable(list_sh *data)
{
	struct stat sts;
	int i;
	char *token;

	token = data->argc[0];
	for (i = 0; token[i]; i++)
	{
		if (token[i] == '.')
		{
			if (token[i + 1] == '.')
				return (0);
			if (token[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (token[i] == '/' && i != 0)
		{
			if (token[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(token + i, &sts) == 0)
	{
		return (i);
	}
	find_error(data, 127);
	return (-1);
}

/**
 * error_cmd - checks access of user
 * @diry: directory
 * @data: data
 * Return: zero
 */
int error_cmd(char *diry, list_sh *data)
{
	if (diry == NULL)
	{
		find_error(data, 127);
		return (1);
	}

	if (_strcmp(data->argc[0], diry) != 0)
	{
		if (access(diry, X_OK) == -1)
		{
			find_error(data, 126);
			free(diry);
			return (1);
		}
		free(diry);
	}
	else
	{
		if (access(data->argc[0], X_OK) == -1)
		{
			find_error(data, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * exec_cmmd - executes commands
 * @data: data
 * Return: success(1)
 */
int exec_cmmd(list_sh *data)
{
	pid_t pdd;
	pid_t wpdd;
	int sts;
	int execute;
	char *dir;
	(void) wpdd;

	execute = isit_executable(data);
	if (execute == -1)
		return (1);
	if (execute == 0)
	{
		dir = _locate(data->argc[0], data->_env);
		if (error_cmd(dir, data) == 1)
			return (1);
	}

	pdd = fork();
	if (pdd == 0)
	{
		if (execute == 0)
			dir = _locate(data->argc[0], data->_env);
		else
			dir = data->argc[0];
		execve(dir + execute, data->argc, data->_env);
	}
	else if (pdd < 0)
	{
		perror(data->argv[0]);
		return (1);
	}
	else
	{
		do {
			wpdd = waitpid(pdd, &sts, WUNTRACED);
		} while (!WIFEXITED(sts) && !WIFSIGNALED(sts));
	}

	data->status = sts / 256;
	return (1);
}
