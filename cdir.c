#include "shell.h"
/**
 * _cd - change directory builtin.
 * @argv: argument to work with.
 * Return: int.
 */
int _cd(char *argv[])
{
	char *oldpwd = NULL, *newpath, *pathbit, *newptr;
	char *homestr = "HOME", *oldpwdstr = "OLDPWD";
	int ret, printpath = 0;

	oldpwd = getcwd(oldpwd, 0);
	if (oldpwd == NULL)
		return (1);

	if (argv[1] == NULL || argv[1][0] == 0)
	{
		newpath = _getenv(homestr);
		if (newpath == homestr)
			newpath = _strdup("");
		argv[1] = newpath;
		argv[2] = NULL;
	}
	else if (argv[1][0] == '-' && argv[1][1] == 0)
	{
		newpath = _getenv(oldpwdstr);
		if (newpath == oldpwdstr)
			newpath = _strdup("");
		printpath = 1;
		free(argv[1]);
		argv[1] = newpath;
	}
	newpath = malloc(sizeof(char) * (_strlen(oldpwd) + _strlen(argv[1]) + 2));
	if (newpath == NULL)
	{
		free(oldpwd);
		return (-1);
	}

	newptr = newpath;
	pathbit = oldpwd;
	if (argv[1][0] != '/' && pathbit[1] != 0)
	{
		while (*pathbit)
			*newptr++ = *pathbit++;
	}
	*newptr++ = '/';
	pathbit = strtok(argv[1], "/");

	while (pathbit != NULL)
	{
		if (pathbit[0] == '.' && pathbit[1] == '.'
		    && pathbit[2] == 0)
		{
			newptr--;
			if (newptr != newpath)
				newptr--;
			while (*newptr != '/')
				newptr--;
			*newptr++ = '/';
		}
		else if (!(pathbit[0] == '.' && pathbit[1] == 0))
		{
			while (*pathbit)
				*newptr++ = *pathbit++;
			*newptr++ = '/';
		}
		pathbit = strtok(NULL, "/");

	}
	if (newptr != newpath && newptr != newpath + 1)
		newptr--;
	*newptr = 0;

	ret = chdir(newpath);
	if (ret == 0)
	{
		_setenv("OLDPWD", oldpwd);
		free(oldpwd);
		_setenv("PWD", newpath);
		if (printpath)
			write(1, newpath, _strlen(newpath));
		free(newpath);
		return (0);
	}
	write(2, "Error: cd: can't cd to \n", 24);
	free(oldpwd);
	free(newpath);
	return (ret);
}
