#include "shell.h"

/**
 * print_env - function to print the environment variable.
 */

void print_env(void)
{
	char **environ = *(getenviron());

	while (*environ)
	{
		int i = 0;

		while ((*environ)[i] != '\0')
		{
			i++;
		}
		write(STDOUT_FILENO, *environ, i);
		write(STDOUT_FILENO, "\n", 1);
		environ++;
	}
}

/**
 * _setenv - set environment for new value.
 * @variable: name of variable.
 * @value: value of variable.
 * Return: 0 or setallenv if success, -1 if fail
 */
int _setenv(char *variable, char *value)
{
	char ***environroot = getenviron();
	char **environ = *environroot;
	int i, j, varz, valz;
	char *s, *ptr;

	if (variable == NULL || value == NULL)
		return (0);
	varz = _strlen(variable);
	valz = _strlen(value);
	ptr = malloc(sizeof(char) * (varz + valz + 2));
	if (ptr == NULL)
		return (-1);
	s = ptr;
	_strcpy(s, variable);
	s += varz;
	_strcpy(s++, "=");
	_strcpy(s, value);
	s += valz;
	*s = 0;
	i = 0;

	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;
		while (s[j] == variable[j])
		{
			j++;
			if (variable[j] == 0 && s[j] == '=')
			{
				free(environ[i]);
				environ[i] = ptr;
				return (0);
			}
		}
		i++;
	}
	return (setallenv(*environroot, ptr));
}

/**
 * _unsetenv - unset environment
 * @name: name of variable to unset
 * Return: 0 if sucess
 */
int _unsetenv(char *variable)
{
	char **environ = *getenviron();
	int i, j;
	int check = 0;
	char *s;
	char **env;

	if (variable == NULL)
		return (0);

	i = 0;

	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;
		while (s[j] == variable[j])
		{
			j++;
			if (s[j] == '=' && variable[j] == '\0')
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
		i++;
	}
	free(environ[i]);
	while (environ[i] != NULL)
	{
		environ[i] = environ[i + 1];
		i++;
	}
	environ[i] = NULL;
	env = environ;
	setallenv(env, NULL);
	i = 0;

	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return (0);
}
