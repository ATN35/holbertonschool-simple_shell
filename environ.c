#include "shell.h"

/**
 * print_env - Prints the environment built-in
 * @command: pointer to tokenized command.
 * Return: Nothing to returns
 */
void print_env(char **command)
{
	int index;
	char nc = '\n';

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}
	free_cm(command);
}
