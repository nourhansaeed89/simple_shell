

#include "my_shell.h"

int main(void)
{
	char user_input[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (read_user_input(user_input) == 0)
		{
		printf("\n");
		break;
		}

	if (execute_user_command(user_input) == -1)
	{
		fprintf(stderr, "Error executing command: %s\n", user_input);
	}
	}
	return (0);
}

