#include "shell.h"

/**
 * set_environment - set the environment variables for the shell.
 */
void set_environment(void)
{
	int i;
	char **env_copy = malloc(sizeof(char *) * (MAX_ENV_VARS + 1));

	if (env_copy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	i = 0;

	while (environ[i] != NULL && i < MAX_ENV_VARS)
	{
		env_copy[i] = _strdup(environ[i]);
		if (env_copy[i] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	env_copy[i] = NULL;

	if (setallenv(env_copy, NULL) == -1)
	{
		perror("Error setting environment variables");
		exit(EXIT_FAILURE);
	}
}

/**
 * setallenv - to set the environment variables.
 * @envin: the environment variables.
 * @newval: new value of the env.
 * Return: 0 on success.
 */
int setallenv(char **envin, char *newval)
{
	static char **environ;
	size_t i, j, len = 0;

	while (envin[len] != NULL)
	{
		len++;
	}

	environ = malloc(sizeof(char *) * (len + 1));
	if (environ == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}

	for (i = 0; i < len; i++)
	{
		environ[i] = _strdup(envin[i]);
		if (environ[i] == NULL)
		{
			perror("Memory allocation error");
			for (j = 0; j < i; j++)
			{
				free(environ[j]);
			}
			free(environ);
			return (-1);
		}
	}
	add_new_value(environ, newval);
	return (0);
}

/**
 * add_new_value - adds new value to the setallenv.
 * @environ: pointer to the environ.
 * @newval: pointer to the new value.
 * Return: 0 on success, -1 on failure.
 */
int add_new_value(char **environ, char *newval)
{
	size_t j, len = 0;

	if (newval != NULL)
	{
		environ[len] = _strdup(newval);
		if (environ[len] == NULL)
		{
			perror("Memory allocation error");
			for (j = 0; j < len; j++)
			{
				free(environ[j]);
			}
			free(environ);
			return (-1);
		}
		len++;
	}

	environ[len] = NULL;

	return (0);
}

/**
 * print_env - print the environment variable
 */
void print_env(void)
{
	int len;
	char **env = environ;

	if (env == NULL)
	{
		return;
	}

	while (*env != NULL)
	{
		len = _strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
 * getallenv - to get the environment variable.
 * Return: pointer to the environ.
 */
char ***getallenv()
{
	static char **environ;

	char ***environ_ptr = &environ;

	return (environ_ptr);
}
