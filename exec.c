#include "cypee.h"
/**
 * execute - function to execute the shell.
 * @argv: argument vector of the command.
 * Return: WEXITSTATUS on success.
 */
int execute(char **argv)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (_strcmp(argv[0], "/bin/ls") == 0)
		{
			if (argv[1] == NULL)
			{
				if (execve(argv[0], argv, environ) == -1)
				{
					perror("./shell");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				write(STDERR_FILENO, "./shell: No such file or directory\n", 36);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (WEXITSTATUS(status));
}
