#include "cypee.h"
/**
 * cy_strtok - my custom strtok function to tokenize command strings.
 * @command: inputted string from the stdin.
 * @delim: pointer to the delimiter.
 * @cyp_ptr: pointer to the command string.
 * Return: the individual tokens.
 */
char *cy_strtok(char *command, const char *delim, char **cyp_ptr)
{
	char *token;

	if (command)
	{
		*cyp_ptr = command;
	}

	if (*cyp_ptr == NULL || **cyp_ptr == '\0')
	{
		return (NULL);
	}

	token = *cyp_ptr;

	while (**cyp_ptr != '\0')
	{
		if (_strchr(delim, **cyp_ptr))
		{
			**cyp_ptr = '\0';
			(*cyp_ptr)++;
			return (token);
		}
		(*cyp_ptr)++;
	}

	return (token);
}
