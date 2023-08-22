#include "shell.h"

/**
 * free_cm - function that frees all the memory allocated for command.
 * @command: pointer to allocated memory to free.
 *
 */
void free_cm(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
}


/**
 * free_exit - function that frees all the memory allocated and exit.
 * @command: pointer to allocated command memory to free.
 *
 */
void free_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}
