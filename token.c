#include "cypee.h"

void tokenizer(char *command, char *argv[])
{
        const int MAX_ARGS = DC_SIZE;
        char *token;
        int argc = 0;

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
                token = strtok(command, " ");
                while (token != NULL && argc < MAX_ARGS - 1)
                {
                        argv[argc++] = token;
                        token = strtok(NULL, " ");
                }
        }
        argv[argc] = NULL;
}
