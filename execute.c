execute.c#include "shell.h"

/**
 * executeCommand - that uses fork and execve to execute the provided command
 * @cmd: pointer to a string
 * @args: pointer to an array of strings
 */
void executeCommand(char *cmd, char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execvp(cmd, args);
		executionError(cmd);
		exit(1);
	}
	else if (pid < 0)
	{
		forkError();
	}
	else
	{
		wait(NULL);
	}
}
