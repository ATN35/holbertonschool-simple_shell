#include "shell.h"

/**
 * main - shell entry point
 * @ac: number of input arguments
 * @av: array of input arguments
 * @env: array of environmental variables
 * Return: always 0
 */
void printPrompt(void) {
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

void printError(char *msg) {
	perror(msg);
}

void printEnvironment(char *env[]) {
	int i;
	for (i = 0; env[i] != NULL; i++) {
		printf("%s\n", env[i]);
	}
}

void executeCommand(char *cmd, char *args[]) {
	pid_t pid = fork();

	if (pid == 0) {
		execvp(cmd, args);
		printError("Erreur lors de l'exécution de la commande");
		exit(1);
	} else if (pid < 0) {
		printError("Erreur lors de la création du processus");
	} else {
		wait(NULL);
	}
}

void freeTokens(char *tokens[]) {
	int i;
	for (i = 0; tokens[i] != NULL; i++) {
		free(tokens[i]);
	}
}

int tokenizeCommand(char *cmd, char *tokens[]) {
	int i = 0;
	char *token = strtok(cmd, " ");

	while (token != NULL && i < MAX_ARGS - 1) {
		tokens[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}

	tokens[i] = NULL;
	return (i);
}

void exitShell(void) {
	printf("Au revoir !\n");
	exit(0);
}

char **getPath(void) {
	int i = 0;
	char *pathvalue = getenv("PATH");

	if (pathvalue == NULL)
		return (NULL);

	char **path = malloc(MAX_ARGS * sizeof(char *));
	if (path == NULL) {
		perror("Allocation de mémoire pour path a échoué");
		exit(1);
	}

	char *token = strtok(pathvalue, ":");
	while (token != NULL && i < MAX_ARGS - 1) {
		path[i] = strdup(token);
		token = strtok(NULL, ":");
		i++;
	}

	path[i] = NULL;
	return (path);
}

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

		int numArgs = tokenizeCommand(input, args);

		bool found = false;
		for (i = 0; path[i] != NULL; i++) {
			char *cmdPath = malloc(strlen(path[i]) + strlen(args[0]) + 2);
			if (cmdPath == NULL) {
				perror("Allocation de mémoire pour cmdPath a échoué");
				exit(1);
			}

			sprintf(cmdPath, "%s/%s", path[i], args[0]);

			if (access(cmdPath, X_OK) == 0) {
				executeCommand(cmdPath, args, env);
				free(cmdPath);
				found = true;
				break;
			}

			free(cmdPath);
		}

		if (!found) {
			printf("Commande introuvable : %s\n", args[0]);
		}

		freeTokens(args);
	}

	for (i = 0; path[i] != NULL; i++) {
		free(path[i]);
	}
	free(path);

	return (0);
}
