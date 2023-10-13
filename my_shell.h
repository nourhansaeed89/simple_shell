
#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_COMMAND_LENGTH 1024

void display_prompt(void);
int read_user_input(char *user_input);
int execute_user_command(char *user_command);
char user_input[MAX_COMMAND_LENGTH];
int execute_command(char *command);

#endif

