#include "main.h"

/**
 * main - entry point
 *
 * Return: void
 */

int main(void)
{
	char *input_buffer = NULL;
	size_t buffer_size = 0;
	ssize_t characters_read;

	while (1)
	{
		printf("$");
		fflush(stdout);

		characters_read = getline(&input_buffer, &buffer_size, stdin);

		if (characters_read == -1)
		{
			perror("getline");
			break;
		}

		if (characters_read > 0)
		{
			if (input_buffer[characters_read - 1] == '\n')
				input_buffer[characters_read - 1] = '\0';

			execute_command(input_buffer);
		}
	}

		free(input_buffer);

	return (EXIT_SUCCESS);
}

