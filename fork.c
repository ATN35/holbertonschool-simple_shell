#include "shell.h"

/**
 * _fork - function that creates a sub process (child).
 * @command: pointer to tokenized command.
 * @name: pointer to the name of shell.
 * @env: pointer to the enviromental variables.
 * @i: number of time its executed.
 * Return: Nothing.
 */
void _fork(char **command, char *name, char **env, int i)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execute(command, name, env, i);
		free_cm(command);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(command);
		}
		free_cm(command);
	}
}
