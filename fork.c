#include "shell.h"

/**
 * _fork - function that creates a child process to execute a command
 * @command: pointer to tokenized command
 * @name: pointer to the name of the shell
 * @env: pointer to the environmental variables
 * @i: number of times it's executed
 * Return: Nothing
 */
void _fork(char **command, char *name, char **env, int i)
{
	int pid, status, wait_error;

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
			perror("Error: ");
			free_exit(command);
		}
		free_cm(command);
	}
}
