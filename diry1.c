#include "main.h"

/**
 * cddot - go to parent dir
 * @data: data
 * Return: no value
 */
void cddot(list_sh *data)
{
	char _pwd[PATH_MAX];
	char *diry, *cpypwd, *pwdtok;

	getcwd(_pwd, sizeof(_pwd));
	cpypwd = _strdup(_pwd);
	set_environ("OLDPWD", cpypwd, data);
	diry = data->argc[1];
	if (_strcmp(".", diry) == 0)
	{
		set_environ("PWD", cpypwd, data);
		free(cpypwd);
		return;
	}
	if (_strcmp("/", cpypwd) == 0)
	{
		free(cpypwd);
		return;
	}
	pwdtok = cpypwd;
	rev_string(pwdtok);
	pwdtok = _strtok(pwdtok, "/");
	if (pwdtok != NULL)
	{
		pwdtok = _strtok(NULL, "\0");

		if (pwdtok != NULL)
			rev_string(pwdtok);
	}
	if (pwdtok != NULL)
	{
		chdir(pwdtok);
		set_environ("PWD", pwdtok, data);
	}
	else
	{
		chdir("/");
		set_environ("PWD", "/", data);
	}
	data->status = 0;
	free(cpypwd);
}

/**
 * cdgo - go to dir
 * @data: data
 * Return: no value
 */
void cdgo(list_sh *data)
{
	char _pwd[PATH_MAX];
	char *diry, *cpypwd, *cpydir;

	getcwd(_pwd, sizeof(_pwd));

	diry = data->argc[1];
	if (chdir(diry) == -1)
	{
		find_error(data, 2);
		return;
	}

	cpypwd = _strdup(_pwd);
	set_environ("OLDPWD", cpypwd, data);

	cpydir = _strdup(diry);
	set_environ("PWD", cpydir, data);

	free(cpypwd);
	free(cpydir);

	data->status = 0;

	chdir(diry);
}

/**
 * cdprv - change to previous dir
 * @data: data
 * Return: no value
 */
void cdprv(list_sh *data)
{
	char _pwd[PATH_MAX];
	char *ppwd, *_oldpwd, *cpypwd, *cpyoldpwd;

	getcwd(_pwd, sizeof(_pwd));
	cpypwd = _strdup(_pwd);

	_oldpwd = _getenv("OLDPWD", data->_env);

	if (_oldpwd == NULL)
		cpyoldpwd = cpypwd;
	else
		cpyoldpwd = _strdup(_oldpwd);

	set_environ("OLDPWD", cpypwd, data);

	if (chdir(cpyoldpwd) == -1)
		set_environ("PWD", cpypwd, data);
	else
		set_environ("PWD", cpyoldpwd, data);

	ppwd = _getenv("PWD", data->_env);

	write(STDOUT_FILENO, ppwd, _strlen(ppwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cpypwd);
	if (_oldpwd)
		free(cpyoldpwd);

	data->status = 0;

	chdir(ppwd);
}

/**
 * cdhome - goto home dir
 * @data: data
 * Return: no value
 */
void cdhome(list_sh *data)
{
	char *ppwd, *home;
	char _pwd[PATH_MAX];

	getcwd(_pwd, sizeof(_pwd));
	ppwd = _strdup(_pwd);

	home = _getenv("HOME", data->_env);

	if (home == NULL)
	{
		set_environ("OLDPWD", ppwd, data);
		free(ppwd);
		return;
	}

	if (chdir(home) == -1)
	{
		find_error(data, 2);
		free(ppwd);
		return;
	}

	set_environ("OLDPWD", ppwd, data);
	set_environ("PWD", home, data);
	free(ppwd);
	data->status = 0;
}
