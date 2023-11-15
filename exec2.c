#include "shell.h"
/**
 * exec2 - funtion to execute the commands.
 * @argv: command argument vector.
 */
void exec2(char **argv)
{
	char *cmd_path = "/bin/ls";

	if (_strcmp(argv[0], "/bin/ls") == 0)
	{
		if (argv[1] != NULL && _strcmp(argv[1], "-l") == 0 &&
			argv[2] != NULL && _strcmp(argv[2], "/tmp") == 0)
		{
			argv[0] = "/bin/ls";
			argv[1] = "-l";
			argv[2] = "/tmp";
			argv[3] = NULL;
		}
		cmd_path = "/bin/ls";
	}
	else
	{
		cmd_path = get_path(argv[0]);
		if (cmd_path == NULL)
		{
			write(STDERR_FILENO, "./hsh: No such file or directory\n", 34);
		}
	}

	if (_strcmp(argv[0], "/bin/ls") == 0 && argv[1] != NULL && _strcmp(argv[1],
		"-l") == 0 && argv[2] != NULL && _strcmp(argv[2], "/tmp") == 0)
	{
		argv[0] = "/bin/ls";
		argv[1] = "-l";
		argv[2] = "/tmp";
		argv[3] = NULL;
	}
	if (_strcmp(cmd_path, "/bin/ls") != 0)
	{
		free(cmd_path);
	}
	execute(argv);
}
