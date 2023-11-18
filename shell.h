#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

#define DC_SIZE 1024
#define MAX_ENV_VARS 100
#define MAX_COMMANDS 10
#define MAX_ARGS 100

extern char **environ;

char *getline_prompt(char **command, size_t *len);
void tokenizer(char *command, char *argv[]);
int execute(char **argv);
int execute_main(char **argv);
void exec2(char **argv);
char *get_path(char *command);
void cy_builtins(char **argv);
void print_env(void);
char *_getenv(char *variable);
void setallenv(char **env);
int _setenv(char *variable, char *value);
int _unsetenv(char *variable);
void free_environ_memory(void);
char *_strtok(char *str, char *delim);
char *strtok2(char *str, char *delim, int escflags);
int _getline(char **command_ptr, int fd);
int _atoi(char *s);
int _cd(char *argv[]);
void cmd_separator(char *command);

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif
