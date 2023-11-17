#include "shell.h"

/**
 * cy_builtins - function to handle built-in commands.
 *
 * @argv: command arguments vector.
 */

void cy_builtins(char **argv)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			int status = _atoi(argv[1]);

			exit(status);
		}
		else
		{
			exit(0);
		}
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL)
		{
			if (_setenv(argv[1], argv[2]) != 0)
			{
				write(STDERR_FILENO, "Error: setenv failed\n", 21);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			write(STDOUT_FILENO, "Fix setenv argument\n", 20);
		}
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] != NULL)
		{
			if (_unsetenv(argv[1]) != 0)
			{
				write(STDERR_FILENO, "Error: unsetenv failed\n", 23);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			write(STDOUT_FILENO, "Usage: unsetenv VARIABLE\n", 25);
		}
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		if (_cd(argv) != 0)
		{
			write(STDERR_FILENO, "Error: cd failed\n", 17);
		}
	}
}
