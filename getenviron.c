#include "shell.h"

/**
 * getenviron - static character wrapper copy whole environ.
 *
 * Return: environ address.
 */

char ***getenviron()
{
	static char **environ;

	return (&environ);
}

/**
 * getallenv - get all environment.
 * Return: environment.
 */
char **getallenv()
{
	char **environ = *(getenviron());
	char **envcopy;
	size_t len = 0;

	envcopy = environ;
	while (envcopy[len] != NULL)
		len++;

	envcopy = malloc(sizeof(char **) * (len + 1));
	if (envcopy == NULL)
		return (NULL);
	while (len > 0)
	{
		envcopy[len] = environ[len];
		len--;
	}
	envcopy[len] = environ[len];
	return (envcopy);
}

/**
 * setallenv - set whole environment for new value
 * @envin: environment
 * @newval: new value to be added
 * Return: 0 if success, -1 if failure
 */
int setallenv(char **envin, char *newval)
{
	char ***environ = getenviron();
	size_t len = 0;

	while (envin[len] != NULL)
		len++;
	if (newval != NULL)
		len++;
	*environ = malloc(sizeof(char **) * (len + 1));
	if (*environ == NULL)
		return (-1);
	for (len = 0; envin[len] != NULL; len++)
		if (newval == NULL)
		{
			(*environ)[len] = _strdup(envin[len]);
		}
		else
			(*environ)[len] = envin[len];
	if (newval != NULL)
	{
		(*environ)[len] = newval;
		len++;
	}
	(*environ)[len] = NULL;

	if (newval != NULL)
		free(envin);
	return (0);
}

/**
 * _getenv - get local environment
 * @name: environment variable
 * Return: string of local environment
 */
char *_getenv(char *variable)
{
	char **environ = *(getenviron());
	int i, j;
	char *s;

	i = 0;
	while (environ[i] != NULL)
	{
		s = environ[i];
		j = 0;

		while (s[j] == variable[j])
		{
			j++;
			if (variable[j] == 0 && s[j] == '=')
				return (_strdup(s + j + 1));
		}
		i++;
	}
	return (variable);
}
