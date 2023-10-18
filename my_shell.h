
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


int execute_command(char *command);
void display_prompt(void);
int read_user_input(char *user_input);
int execute_user_command(char *user_command);
char user_input[MAX_COMMAND_LENGTH];
int execute_command(char *command);
char **tokenize_input(char *input);
int execute_command(char **args);
char *find_command(const char *command);
void error(const char* message);
void execute_command(const char* command);
void error(const char* message);
void execute_command(const char* command);
void handle_signal(int signum);
void execute_exit(void);
void run_shell();
void execute_env();
void run_shell();
void execute_env();


#endif

