#include "main.h"

/**
 * eshell - myshell program
 * Return: detailed information on code.
 */
int eshell(void)
{
	char *line = NULL;
	char *Path = NULL;
	char **copy_line = NULL;
	ssize_t ncharstoread;
	unsigned int status = 1;
	size_t num = 0;

	write(STDOUT_FILENO, "MyShell$ ", 9);
	ncharstoread = getline(&line, &num, stdin);
	if (ncharstoread == -1)
	{
		status = _SHELL_END_, write(STDOUT_FILENO, "\n", 1);
	}
	if (ncharstoread == 1)
	{
		status = _SKIP_;
	}

	if (status == _NORMAL_)
	{
		copy_line = _strtok(&line, "' '\n\t");
	}
	if (status == _NORMAL_)
	{
		status = builtin(copy_line);
	}

	if (status == _NORMAL_ && (copy_line[0][0] != '.' && copy_line[0][1] != '/'))
	{
		Path = get_path(copy_line[0]);
	}
	if (status == _NORMAL_)
	{
		execmd(Path ? Path : copy_line[0], copy_line), wait(NULL);

		free(line);
		free(copy_line);
		free(Path);
	}
	return (status);
}
