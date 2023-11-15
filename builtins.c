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
		exit(0);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
}
