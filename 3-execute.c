#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 100

char **tokenize_input(char *input);
int execute_command(char **args);
char *find_command(const char *command);
int main() {
char nput[MAX_INPUT_SIZE];

  while (1) {
   printf("SimpleShell> ");

   if (fgets(input, sizeof(input), stdin) == NULL) {
	          break;
	           }

// Remove the newline character
input[strcspn(input, "\n")] = '\0';

char **args = tokenize_input(input);

        if (args[0] == NULL) {
            // No command entered, continue
continue;
	}

	int status = execute_command(args);
	free(args);
  }
  return 0;
}
char **tokenize_input(char *input) {
	char **args = malloc(MAX_ARGUMENTS * sizeof(char *));
	if (args == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	// Tokenize the input string into arguments
	  char *token = strtok(input, " ");
	  int i = 0;
	  while (token != NULL) {
		  args[i] = strdup(token);
		  if (args[i] == NULL) {
			  perror("strdup");
			  exit(EXIT_FAILURE);
		  }
		  token = strtok(NULL, " ");
		  i++;
	  }
	  args[i] = NULL;

	  return args;
}

int execute_command(char **args) {
	char *command = args[0];
	char *command_path = find_command(command);

	if (command_path == NULL) {
		fprintf(stderr, "Command not found: %s\n", command);
		return 1;
	}
	pid_t child_pid = fork();
	    if (child_pid == -1) {
		            perror("fork");
			    exit(EXIT_FAILURE);
			        } else if (child_pid == 0) {
					// Child process
 			       execve(command_path, args, NULL);
  		               perror("execve");
  		                exit(EXIT_FAILURE);
                      // Parent process
		        int status;
 		        wait(&status);
  		        return WEXITSTATUS(status);
            }
}
char *find_command(const char *command) {
	// TODO: Implement code to search for the command in the PATH
	  return NULL;
}
