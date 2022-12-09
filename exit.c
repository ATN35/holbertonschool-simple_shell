#include "shell.h"

/**
 * exitshell - function that exits the shell.
 * @command: pointer to tokenized command.
 * @j: status for task 5 checker
 */
void exitshell(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		free_cm(command);
		exit(EXIT_SUCCESS);
	}
	if (j == 2)
	{
		free_cm(command);
		exit(j);
	}
	status = _atoi(command[1]);
	free_cm(command);
	exit(status);
}
