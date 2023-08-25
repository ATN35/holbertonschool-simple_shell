#include "shell.h"


/**
 * tokenizeCommand - the input command and returns the number of arguments
 * @cmd: the command to divide
 * @tokens: the array of string pointers to store tokens
*/
void tokenizeCommand(char *cmd, char *tokens[])
{
	int i = 0;
	char *token = strtok(cmd, " ");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}

	tokens[i] = NULL;
}
