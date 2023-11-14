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
			exit(atoi(argv[1]));
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
	else if (strcmp(argv[0], "ls") != 0 && strcmp(argv[0], "/bin/ls") != 0)
	{
		execute(argv);
	}
}
/**
 * cy_builtins2 - function to handle built-in commands.
 *
 * @argv: command arguments vector.
 */
void cy_builtins2(char **argv)
{
	if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL)
		{
			setenv_variable(argv[1], argv[2]);
		}
		else
		{
			write(STDERR_FILENO, "Error: Incorrect syntax for setenv\n", 35);
		}
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] != NULL)
		{
			unsetenv_variable(argv[1]);
		}
		else
		{
			write(STDERR_FILENO, "Error: Incorrect syntax for unsetenv\n", 38);
		}
	}
}
