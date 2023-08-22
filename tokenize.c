#include "shell.h"

/**
 * tokenize - function that splits and creates an array of command tokens
 * @line: the input string to tokenize
 * @delim: the delimiter used for strtok
 * Return: an array of command tokens
 */
char **tokenize(char *line, const char *delim)
{
	char *token = NULL, **tokens = NULL;
	size_t bufsize = 100;
	int i = 0;

	if (line == NULL || delim == NULL)
		return NULL;

	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Unable to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = malloc(strlen(token) + 1);
		if (tokens[i] == NULL)
		{
			perror("Unable to allocate memory");
			free_tokens(tokens, i);
			exit(EXIT_FAILURE);
		}
		strcpy(tokens[i], token);
		token = strtok(NULL, delim);
		i++;

		if (i >= bufsize)
		{
			bufsize += 100;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				perror("Unable to reallocate memory");
				free_tokens(tokens, i);
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[i] = NULL;
	return tokens;
}
