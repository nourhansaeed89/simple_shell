#include "my_shell.h"
/**
 * execute_command - Executes the command
 * @command: The command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
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
	return (0);
}

