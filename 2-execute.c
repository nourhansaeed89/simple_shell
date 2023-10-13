#include "main.h"
/**
 * execute_command - excute command
 * @command: input command
 *
 * Return: command
 */
int execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *token;
		char *args[1024];
		int i = 0;

		token = strtok(command, " ");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
			args[i] = NULL;

		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (EXIT_SUCCESS);
}

