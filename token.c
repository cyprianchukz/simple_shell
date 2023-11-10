#include "cypee.h"

/**
 * tokenizer - function to tokenize user input/command.
 *
 * @command: inputed command from the stdin.
 * @argv: command arguments vector.
 */

void tokenizer(char *command, char *argv[])
{
	char *token;
	int argc = 0;

	token = strtok(command, " ");

	while (token != NULL && argc < DC_SIZE - 1)
	{
		argv[argc++] = token;
		token = strtok(NULL, " ");
	}
	argv[argc] = NULL;
}
