#include "shell.h"

/**
 * exitshell - function that exits the shell.
 * @command: pointer to tokenized command.
 *
 */
void exitshell(char **command)
{
	int status = 0;
	char status_str[10];

	if (command[1] == NULL)
	{
		free_cm(command);
		exit(EXIT_SUCCESS);
	}
	status = _atoi(command[1]);

	sprintf(status_str, "%d", status);

	free_cm(command);
	exit(status);
}
