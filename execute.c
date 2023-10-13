#include "my_shell.h"

/**
 *
 * display_prompt - make flush
 *
 * Return: void
 */

void display_prompt(void)
{
	printf("#myshell$ ");
	fflush(stdout);
}

/**
 * read_user_input - func that read from user
 * @user_input: user input
 *
 * Return: rrturn 1 if user give input
 */

int read_user_input(char *user_input)
{

	if (fgets(user_input, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
	return (0);
	}

	user_input[strcspn(user_input, "\n")] = '\0';
	return (1);
}
/**
 * execute_user_command - func that excute user command
 *
 * @user_command: usercomand
 *
 * Return: -1 if no command else return 0
 */

int execute_user_command(char *user_command)
{
	char *command_args[2];
	int status;

	command_args[0] = user_command;
	command_args[1] = NULL;

	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{

		if (execve(command_args[0], command_args, NULL) == -1)
		{
		perror("execve");
		return (-1);
		}
	}
	else
	{

		wait(&status);
	}

	return (0);
}
