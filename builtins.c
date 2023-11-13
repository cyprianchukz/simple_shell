#include "cypee.h"

/**
 * cy_builtins - function to handle built-in commands.
 *
 * @argv: command arguments vector.
 */

void cy_builtins(char **argv)
{
	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
			int status = atoi(argv[1]);
			exit(status);
		}
		else
		{
			exit(0);
		}
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL)
		{
			setenv_variable(argv[1], argv[2]);
		}
		else
		{
			write(STDOUT_FILENO, "Usage: setenv VARIABLE\n", 22);
		}	
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] != NULL)
		{
			unsetenv_variable(argv[1]);
		}
		else
		{
			write(STDOUT_FILENO, "Usage: unsetenv VARIABLE\n", 25);
		}
	}
}
