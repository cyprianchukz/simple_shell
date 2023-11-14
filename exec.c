#include "cypee.h"
/**
 * execute - funtion to execute the commands.
 * @argv: command argument vector.
 * Return: the exit status (WEXITSTATUS).
 */
int execute(char **argv)
{
	pid_t child;
	int status;
	char *cmd_path = "/bin/ls";

	child = fork();
	if (child == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}

	return (WEXITSTATUS(status));
}
