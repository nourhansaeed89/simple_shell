#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void execute_env() {
	    // Use the `environ` global variable to access environment variables
	   extern char** environ;

	   // Iterate through the environment variables and print them
	   for (int i = 0; environ[i] != NULL; i++) {
		           printf("%s\n", environ[i]);
	   }
}
int main() {
    char input[1024];

     while (1) {
             printf("MyShell> ");
             fgets(input, sizeof(input), stdin);

	     // Remove the newline character from the input
	    input[strcspn(input, "\n")] = '\0';

	     if (strcmp(input, "env") == 0) {
		                 execute_env();
			         } else if (strcmp(input, "exit") == 0) {
				             exit(0);
				 } else {
					 // You can implement other commands here
					printf("Unknown command: %s\n", input);
				 }
     }
     return (0);
}
