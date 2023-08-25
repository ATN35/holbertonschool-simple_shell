#include "shell.h"

/**
 * msgerror - function that prints message not found.
 * @name: name of the shell.
 * @i: i.
 * @command: pointer to tokenized command.
 */
void msgerror(char *name, int i, char **command)
{
	char c;

	c = i + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
