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
	char *error_format = ": %c: %s%s";

	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, error_format, c, command[0], error_message);
}
