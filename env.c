#include "shell.h"

/**
 * print_env - function to print the environment variable.
 */

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		int i = 0;

		while ((*env)[i] != '\0')
		{
			i++;
		}
		write(STDOUT_FILENO, *env, i);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
