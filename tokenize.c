#include "shell.h"

void tokenizeCommand(char *cmd, char *tokens[]) {
	int i = 0;
	char *token = strtok(cmd, " ");

	while (token != NULL && i < MAX_ARGS - 1) {
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}

	tokens[i] = NULL;
}
