#ifndef CYPEE_H
#define CYPEE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>

#define DC_SIZE 1024

extern char **environ;

char *getline_prompt(char **command, size_t *len);
void tokenizer(char *command, char *argv[]);
int execute(char **argv);
void exec2(char **argv);
char *get_path(char *command);
void cy_builtins(char **argv);
void cy_builtins2(char **argv);
void print_env(void);
char *cy_getline(void);
char *read_command();
char *allocate_memory(int size);
void cy_tokenizer(char *command, char *argv[]);
char *cy_strtok(char *command, const char *delim, char **cyp_ptr);
int setenv_variable(const char *variable, const char *value);
int unsetenv_variable(const char *variable);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strdup(const char *str);
char *_strchr(const char *str, int c);

#endif
