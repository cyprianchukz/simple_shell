#include "cypee.h"

char *get_path(char *command)
{
	char *dir, *token;
	char *path = getenv("PATH");
	char *path_cpy = strdup(path);
	char *cmd_path = NULL;
	int len, i;

	token = strtok(path_cpy, ":");
	while (token != NULL)
	{
		dir = token;
		len = strlen(dir) + strlen(command) + 2;
		cmd_path = malloc(len);
		if (cmd_path == NULL)
		{
			perror("malloc");
			return NULL;
		}

		i = 0;
		cmd_path[i++] = '/';

		while (*command)
		{
			cmd_path[i++] = *command++;
		}
		cmd_path[i] = '\0';

		if (access(cmd_path, X_OK) == 0)
		{
			free(path_cpy);
			return cmd_path;
		}
		free(cmd_path);
		token = strtok(NULL, ":");
	}
	free(path_cpy), path_cpy = NULL;
	return NULL;
}
