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
}
