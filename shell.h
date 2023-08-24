#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_CMD_LENGTH 100
#define MAX_ARGS 10

void printPrompt(void);
void printError(char *msg);
void printEnvironment(char *env[]);
void executeCommand(char *cmd, char *args[]);
void freeTokens(char *tokens[]);
int tokenizeCommand(char *cmd, char *tokens[]);
void exitShell(void);
char **getPath(void);

#endif
