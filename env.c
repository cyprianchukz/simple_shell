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
 * setenv_variable - function to set and update the environment variable.
 * @variable: updated enviroment variable.
 * @value: value of the updated env variable.
 */
void setenv_variable(char *variable, char *value)
{
	if (setenv(variable, value, 1) == -1)
	{
		write(STDERR_FILENO, "Setenv failed\n", 14);
	}
}
/**
 * unsetenv_variable - function to unset the environment variable.
 * @variable: variable to be unset.
 */
void unsetenv_variable(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		write(STDERR_FILENO, "Unsetenv failed\n", 17);
	}
}
