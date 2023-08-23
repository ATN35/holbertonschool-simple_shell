#include "shell.h"

/**
 * msgerror - function that prints "not found" error message
 * @name: name of the shell
 * @i: convert i to a character
 * @command: pointer to tokenized command
 */
void msgerror(char *name, int i, char **command)
{
	char c = i + '0';
	char *error_message = ": not found\n";

	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, error_message, _strlen(error_message));
}
