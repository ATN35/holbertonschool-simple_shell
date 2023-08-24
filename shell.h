#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

void printPrompt(void);
void executeCommand(char *cmd, char *args[]);
void tokenizeCommand(char *cmd, char *tokens[]);
char **getPath(void);
void exitShell(void);
void printEnvironment(char *env[]);
void freeTokens(char *tokens[]);

#endif
