#include "shell.h"
/**
 * _cd - change directory builtin
 * @av: argument to work with
 * Return: int
 */
int _cd(char *av[])
{
	char *oldpwd = NULL, *newpath, *pathbit, *newptr;
	char *homestr = "HOME", *oldpwdstr = "OLDPWD";
	int ret, printpath = 0;

	oldpwd = getcwd(oldpwd, 0);
	if (oldpwd == NULL)
		return (1);
	if (av[1] == NULL || av[1][0] == 0)
	{
		newpath = _getenv(homestr);
		if (newpath == homestr)
			newpath = _strdup("");
		av[1] = newpath;
		av[2] = NULL;
	}
	else if (av[1][0] == '-' && av[1][1] == 0)
	{
		newpath = _getenv(oldpwdstr);
		if (newpath == oldpwdstr)
			newpath = _strdup("");
		printpath = 1;
		free(av[1]);
		av[1] = newpath;
	}

	newpath = malloc(sizeof(char) * (_strlen(oldpwd) + _strlen(av[1]) + 2));
	if (newpath == NULL)
		return (-1);
	newptr = newpath;
	pathbit = oldpwd;
	if (av[1][0] != '/' && pathbit[1] != 0)
		while (*pathbit)
			*newptr++ = *pathbit++;
	*newptr++ = '/';
	pathbit = strtok(av[1], "/");

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
			fprintstrs(1, newpath, "\n", NULL);
		free(newpath);
		return (0);
	}
	write(STDERR_FILENO, "Error: cd: can't cd to \n", 24);
	free(oldpwd);
	free(newpath);
	return (ret);
}
