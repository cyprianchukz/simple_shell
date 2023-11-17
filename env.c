#include "shell.h"

/**
 * print_env - function to print the environment variable.
 */
void print_env(void)
{
	char **env = environ;
	int i;

	while (*env)
	{
		i = 0;

		while ((*env)[i] != '\0')
		{
			i++;
		}
		write(STDOUT_FILENO, *env, i);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * _getenv - get local environment.
 * @variable: the environment variable.
 * Return: string of local environment variable if found.
 * and NULL if not found.
 */
char *_getenv(char *variable)
{
	char *s, *env_value;
	int i, j;

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
				env_value = _strdup(s + j + 1);
				if (env_value == NULL)
				{
					return (NULL);
				}
				return (env_value);
			}
		}
		i++;
	}

	return (NULL);
}

/**
 * _setenv - set new value for the environment variable.
 * @variable: first argument of setenv variable.
 * @value: value and second argument of setenv variable.
 * Return: 0 on success, -1 on failure.
 */
int _setenv(char *variable, char *value)
{
	int i, j, var_len, val_len;
	char *s, *ptr;

	if (variable == NULL || value == NULL)
		return (0);

	var_len = _strlen(variable);
	val_len = _strlen(value);

	ptr = malloc(sizeof(char) * (var_len + val_len + 2));
	if (ptr == NULL)
		return (-1);

	s = ptr;
	_strcpy(s, variable);
	s += var_len;
	_strcpy(s++, "=");
	_strcpy(s, value);
	s += val_len;
	*s = '\0';

	i = 0;

	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;
		while (s[j] == variable[j])
		{
			j++;
			if (variable[j] == '\0' && s[j] == '=')
			{
				free(environ[i]);
				environ[i] = ptr;
				return (0);
			}
		}
		i++;
	}
	free(ptr);

	return (0);
}

/**
 * _unsetenv - function to unset the environment variable.
 * @variable: name of environment variable to unset.
 * Return: 0 on success.
 */
int _unsetenv(char *variable)
{
	int i, j, unset_check = 0;
	char *s, **env;

	if (variable == NULL || environ == NULL)
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
				unset_check = 1;
				break;
			}
		}
		if (unset_check == 1)
			break;
		i++;
	}

	if (environ[i] != NULL)
	{
		free(environ[i]);

		while (environ[i] != NULL)
		{
			environ[i] = environ[i + 1];
			i++;
		}
		environ[i] = NULL;

		env = environ;
		setallenv(env);
		i = 0;

		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
	}
	return (0);
}

/**
 * setallenv - function to update the entire environment.
 * @env: new environment to set.
 * Return: void.
 */
void setallenv(char **env)
{
	int i = 0;
	char **temp = environ;

	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);

	environ = env;
}
