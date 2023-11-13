#include "cypee.h"

/**
 * main - entry point to execute all functions.
 *
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	char *command = NULL;
	bool piped = false;
	(void) argc;

	if (!isatty(STDIN_FILENO))
	{
		piped = true;
		command = cy_getline();
		if (!command)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
	}

	if (piped)
	{
		command[strlen(command) - 1] = '\0';
		cy_tokenizer(command, argv);
		execute(argv);
		free(command);
	}
	else
	{
		while (1 && !piped)
		{
			command = cy_getline();

			if (command != NULL && *command != '\0')
			{
				cy_tokenizer(command, argv);
				cy_builtins(argv);
				execute(argv);
			}
			free(command);
		}
	}
	return (0);
}
