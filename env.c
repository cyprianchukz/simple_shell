#include "cypee.h"
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
/**
 * setenv_variable - Initialize a new environment variable or modify an existing one.
 * @variable: Name of the environment variable.
 * @value: Value to be assigned to the environment variable.
 * Return: 0 on success, -1 on failure.
 */
int setenv_variable(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL)
	{
		write(STDERR_FILENO, "Error: Invalid input for setenv\n", 32);
		return	(-1);
	}

	if (setenv(variable, value, 1) != 0)
	{
		write(STDERR_FILENO, "Error: Failed to set environment variable\n", 42);
		return (-1);
	}

	return 0;
}

/**
 * unsetenv_variable - Remove an environment variable.
 * @variable: Name of the environment variable to be removed.
 * Return: 0 on success, -1 on failure.
 */
int unsetenv_variable(const char *variable)
{
	if (variable == NULL)
	{
		write(STDERR_FILENO, "Error: Invalid input for unsetenv\n", 35);
		return (-1);
	}

	if (unsetenv(variable) != 0)
	{
		write(STDERR_FILENO, "Error: Failed to unset environment variable\n", 45);
        return -1;
    }

    return 0;
}
