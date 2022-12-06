#include "shell.h"

/**
 * tokenize - function that split and create a full string command.
 * @s: The delimiter for strtok.
 * @line: The pointer to input string.
 * Return: A string with full command.
 */
char **tokenize(char *line, const char *s)
{
	char *token = NULL, **commands = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (line == NULL)
		return (NULL);

	bufsize = _strlen(line);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(line);
		free_cm(commands);
		exit(EXIT_FAILURE);
	}

	token = strtok(line, s);
	while (token != NULL)
	{
		commands[i] = malloc(_strlen(token) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			free_cm(commands);
			return (NULL);
		}
		_strcpy(commands[i], token);
		token = strtok(NULL, s);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
