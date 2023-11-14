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
void print_env(void);

int _strcmp(char *s1, char *s2);

#endif
