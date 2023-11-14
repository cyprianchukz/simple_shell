#include "cypee.h"

static char buffer[DC_SIZE];
static int pos;
static int end;
/**
 * cy_getline - my customized getline function with prompt.
 * Return: read command function.
 */
char *cy_getline()
{
	const char *prompt = "~cypee~$ ";

	write(STDOUT_FILENO, prompt, 9);
	return (read_command());
}
/**
 * allocate_memory - allocates memory to the inputted command.
 * @size: size of the inputted command.
 * Return: temp, [pointer to the aloocated memory.
 */
char *allocate_memory(int size)
{
	char *temp = (char *)malloc(size * sizeof(char));

	if (!temp)
	{
		perror("Error: Memory allocation");
		exit(EXIT_FAILURE);
	}
	return (temp);
}
/**
 * read_command - reads the command inputted.
 * Return: command inputted on success.
 */
char *read_command()
{
	int i, command_len = 0;
	char ch, *command;

	command = allocate_memory(DC_SIZE);

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
					return (NULL);
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
			char *temp = allocate_memory(command_len + DC_SIZE);

			for (i = 0; i < command_len; i++)
			{
				temp[i] = command[i];
			}
			free(command), command = temp;
		}
		command[command_len++] = ch;
	}
	command[command_len] = '\0';
	return (command);
}
