#include "shell.h"

/**
 * print_env - Prints the environment built-in
 *
 * Return: Nothing to returns
 */
void print_env(void)
{
	int index;
	char nc = '\n';

	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}
}
