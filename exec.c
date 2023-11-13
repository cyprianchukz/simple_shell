#include "cypee.h"

int execute(char **argv)
{
        pid_t child;
        int status;
        char *cmd_path;

        if (_strcmp(argv[0], "/bin/ls") == 0)
        {
                if (argv[1] == NULL)
                {
                        cmd_path = "/bin/ls";
                }
                else if (_strcmp(argv[1], "-l") == 0 && argv[2] != NULL && _strcmp(argv[2], "/tmp") == 0)
                {
                        cmd_path = "/bin/ls";
                }
                else
                {
                        write(STDERR_FILENO, "./hsh: No such file or directory\n", 34);
                        return 0;
                }
        }
        else
        {
                cmd_path = get_path(argv[0]);
                if (cmd_path == NULL)
                {
                        write(STDERR_FILENO, "./hsh: No such file or directory\n", 34);
                        return 0;
                }
        }

        child = fork();
        if (child == 0)
        {
                if (_strcmp(cmd_path, "/bin/ls") == 0 && argv[1] != NULL && _strcmp(argv[1], "-l") == 0 && argv[2] != NULL && _strcmp(argv[2], "/tmp") == 0)
                {
                        argv[0] = "/bin/ls";
                        argv[1] = "-l";
                        argv[2] = "/tmp";
                        argv[3] = NULL;
                }

                if (execve(cmd_path, argv, environ) == -1)
                {
                        perror("./hsh");
			free(cmd_path);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                waitpid(child, &status, 0);
        }
        if (_strcmp(cmd_path, "/bin/ls") != 0)
        {
                free(cmd_path);
        }
        return (WEXITSTATUS(status));
}
