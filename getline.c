#include "cypee.h"

char *cy_getline(void)
{
	static char buffer[DC_SIZE];
	static int pos = 0;
	static int end = 0;
	const char *prompt = "~cypee~$ ";

	int i, command_len = 0;
	char ch, *command;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 9);

		command = (char *)malloc(DC_SIZE * sizeof(char));

		if (!command)
		{
			perror("Error: malloc");
			exit(EXIT_FAILURE);
		}

		while (1)
		{
			if (pos >= end)
			{
				pos = 0;
				end = read(STDIN_FILENO, buffer, DC_SIZE);
				if (end <= 0)
				{
					if (command_len == 0)
					{
						free(command);
						return NULL;
					}
					else
					{
						break;
					}
				}
			}

			ch = buffer[pos++];
			if (ch == '\n')
			{
				break;
			}

			if (command_len >= DC_SIZE - 1)
			{
				char *temp = (char *)malloc((command_len + DC_SIZE) * sizeof(char));
				if (!temp)
				{
					perror("Error: Memory allocation");
					exit(EXIT_FAILURE);
				}

				for (i = 0; i < command_len; i++)
				{
					temp[i] =command[i];
				}
				free(command);
				command = temp;
			}

			command[command_len++] = ch;
		}

		command[command_len] = '\0';
		return command;
	}
}
