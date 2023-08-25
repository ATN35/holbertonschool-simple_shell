#include "shell.h"

/**
 * main - shell entry point
 * Return: always 0
 */
int main(void)
{
	char input[MAX_CMD_LENGTH];
	char *args[MAX_ARGS];
	char **path = getPath();
	int i;

	while (1)
	{
		printPrompt();
		if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strlen(input) - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			exitShell();
			break;
		}
		tokenizeCommand(input, args);
		executeCommand(args[0], args);
		freeTokens(args);
	}
	for (i = 0; path[i] != NULL; i++)
	{
		free(path[i]);
	}
	free(path);

	return (0);
}
