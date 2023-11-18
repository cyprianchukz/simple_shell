#include "shell.h"
/**
 * execute_main - function to execute the commands.
 * @argv: command argument vector.
 * Return: the exit status (WEXITSTATUS).
 */
int execute_main(char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
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
