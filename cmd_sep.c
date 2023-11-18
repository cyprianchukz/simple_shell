#include "shell.h"

/**
 * cmd_separator - function to handle commands separated by semicolons.
 * @command: input string containing multiple commands separated by semicolons.
 */
void cmd_separator(char *command)
{
	char *commands[MAX_COMMANDS], *token, *argv[MAX_ARGS];
	int i, j, num_commands = 0, argc;
	size_t arg_len;
	char newline = '\n';

	token = _strtok(command, ";");

	while (token != NULL && num_commands < MAX_COMMANDS)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, ";");
	}

	for (i = 0; i < num_commands; i++)
	{
		argc = 0;
		token = strtok(commands[i], " ");

		while (token != NULL && argc < MAX_ARGS - 1)
		{
			argv[argc++] = token;
			token = strtok(NULL, " ");
		}
		argv[argc] = NULL;

		for (j = 0; j < argc; j++)
		{
			arg_len = strlen(argv[j]);
			write(STDOUT_FILENO, argv[j], arg_len);
			if (j != argc - 1)
			{
				char space = ' ';

				write(STDOUT_FILENO, &space, 1);
			}
		}

		write(STDOUT_FILENO, &newline, 1);
	}
}
