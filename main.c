#include "shell.h"

/**
 * main - shell entry point
 * @input: stores user input
 * @args: array to store command arguments
 * @path: array to store PATH paths
 * @i: loop variable
 * Return: always 0
 */
int main(void) {
	char input[MAX_CMD_LENGTH];
	char *args[MAX_ARGS];
	char **path = getPath();
	int i;

	while (1) {
		printPrompt();
		if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL) {
			printf("\n");
			break;
		}
		input[strlen(input) - 1] = '\0';
		if (strcmp(input, "exit") == 0) {
			exitShell();
			break;
		}
		tokenizeCommand(input, args);
		struct stat path_stat;
		if (stat(args[0], &path_stat) == 0) {
			if (S_ISDIR(path_stat.st_mode)) {
				printf("Le chemin est un répertoire.\n");
			} else {
				executeCommand(args[0], args);
			}
		} else {
			printf("Chemin introuvable.\n");
		}
		freeTokens(args);
	}
	for (i = 0; path[i] != NULL; i++) {
		free(path[i]);
	}
	free(path);
	return (0);
}
