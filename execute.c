#include "shell.h"

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
