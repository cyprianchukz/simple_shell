#include "cypee.h"
/**
 * cy_tokenizer - a function to tokenize the command string.
 * @command: command from the stdin or piped.
 * @argv: command argument vector.
 */
void cy_tokenizer(char *command, char *argv[])
{
	const int MAX_ARGS = DC_SIZE;
	char *token;
	int argc = 0;
	char *cyp_ptr;

	if (_strcmp(command, "ls") == 0)
	{
		argv[argc++] = "/bin/ls";
	}
	else if (_strcmp(command, "ls -l /tmp") == 0)
	{
		argv[argc++] = "/bin/ls";
		argv[argc++] = "-l";
		argv[argc++] = "/tmp";
	}
	else
	{
		token = cy_strtok(command, " ", &cyp_ptr);

		while (token != NULL && argc < MAX_ARGS - 1)
		{
			argv[argc++] = token;
			token = cy_strtok(NULL, " ", &cyp_ptr);
		}
	}
	argv[argc] = NULL;
}
