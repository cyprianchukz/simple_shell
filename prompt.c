#include "cypee.h"

/**
 * getline_prompt - a function that prints our prompt
 * and handles user input.
 * @command: inputted command from the stdin.
 * @len: length of the command string.
 * Return: the inputted command on success.
 */
char *getline_prompt(char **command, size_t *len)
{
	char *prompt = "~cypee~$ ";
	ssize_t read;

	write(STDOUT_FILENO, prompt, 9);

	*command = NULL;

	read = getline(command, len, stdin);

	if (read == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(*command);
		exit(EXIT_SUCCESS);
	}

	if (read > 0 && (*command)[read - 1] == '\n')
	{
		(*command)[read - 1] = '\0';
	}
	return (*command);
}
