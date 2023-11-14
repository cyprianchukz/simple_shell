#include "cypee.h"

/**
 * main - entry point to execute all functions.
 * @argc: command argument count.
 * @argv: command argument vector.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	char *command = NULL;
	bool piped = false;
	size_t len = 0;
	(void) argc;

	if (!isatty(STDIN_FILENO))
	{
		piped = true;
		if (getline(&command, &len, stdin) == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
	}

	if (piped)
	{
		command[strlen(command) - 1] = '\0';
		tokenizer(command, argv);
		execute(argv);
		free(command);
	}
	else
	{
		while (1 && !piped)
		{
			getline_prompt(&command, &len);

			if (command != NULL && *command != '\0')
			{
				tokenizer(command, argv);
				cy_builtins(argv);
				if (strcmp(argv[0], "env") != 0)
				{
					exec2(argv);
				}
			}
			free(command);
		}
	}
	return (0);
}
