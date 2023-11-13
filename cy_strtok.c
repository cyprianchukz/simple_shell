#include "cypee.h"

char *cy_strtok(char *command, const char *delim, char **cyp_ptr)
{
	char *token;

	if (command)
	{
		*cyp_ptr = command;
	}

	if (*cyp_ptr == NULL || **cyp_ptr == '\0')
	{
		return NULL;
	}

	token = *cyp_ptr;

	while (**cyp_ptr != '\0')
	{
		if (strchr(delim, **cyp_ptr))
		{
			**cyp_ptr = '\0';
			(*cyp_ptr)++;
			return token;
		}
		(*cyp_ptr)++;
	}

	return token;
}
