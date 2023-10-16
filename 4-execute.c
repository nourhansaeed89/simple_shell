#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024

void execute_exit() {
	    exit(0);
}
int main() {
	    char command[MAX_COMMAND_LENGTH];
	    while (1) {
	            printf("SimpleShell> ");
	            if (fgets(command, sizeof(command), stdin) == NULL) {
	                break; // Exit on EOF (e.g., Ctrl+D)
		    }
		    // Remove the trailing newline character
		     size_t cmd_len = strlen(command);
	             if (cmd_len > 0 && command[cmd_len - 1] == '\n') {
		                 command[cmd_len - 1] = '\0';
		     }
		     if (strcmp(command, "exit") == 0) {
	                 execute_exit();
		         } else {
// Handle other commands or execute them
printf("Executing: %s\n", command);
			 }
	    }
	    return 0;
}
