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
		exit(0);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		print_env();
	}
	else if (strcmp(argv[0], "ls") != 0 && strcmp(argv[0], "/bin/ls") != 0)
	{
		execute(argv);
	}
}
