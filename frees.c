#include "shell.h"

/**
 * freeTokens - frees deployed memory for an array of tokens
 * @tokens: the array of tokens to release
 */
void freeTokens(char *tokens[])
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
}
