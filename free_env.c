#include "shell.h"

/**
 * free_environ_memory - free memory allocated to environ.
 */
void free_environ_memory(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		free(*env_ptr);
		env_ptr++;
	}
}
