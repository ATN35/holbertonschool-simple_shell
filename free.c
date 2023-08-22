#include "shell.h"

/**
 * free_tokens - function to free memory allocated for tokens
 * @tokens: the array of tokens to free
 * @count: the number of tokens in the array
 */
void free_tokens(char **tokens, int count)
{
	for (int i = 0; i < count; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
 * free_cm - function to free memory allocated for commands
 * @command: The array of command tokens to free
 */
void free_cm(char **command)
{
	char **temp = command;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(command);
}

/**
 * free_exit - function that frees all the memory allocated and exit
 * @command: pointer to allocated command memory to free
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
