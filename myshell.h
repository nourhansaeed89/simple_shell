#ifndef MYSHELL_H
#define MYSHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _putchar(char c);

char *_get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
int _fork_fun(char **arg, char **av, char **env,
char *lineptr, int np, int c);
char *_strtok(char *str, const char *delim);

char *_getline_command(void);
char **_get_token(char *getcommand);
int _strcmp(char *s1, char *s2);
void _exit_command(char **user_command, char *getcommand, int _exit);
void _getenv(char **env);
int _values_path(char **user_command, char **env);
int _fork_fun(char **user_command, char **av, char **env, char *getcommand,
		int pathValue, int n);

#endif
