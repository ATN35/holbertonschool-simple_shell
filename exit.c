#include "shell.h"

/**
 * exitshell - function that exits the shell
 * @command: pointer to tokenized command
 *
 */
void exitshell(char **command)
{
	if (command[1] == NULL) {
		free_cm(command);
		exit(EXIT_SUCCESS);
	} else {
		int status = _atoi(command[1]);
		free_cm(command);
		exit(status);
	}
}
