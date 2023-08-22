#include "shell.h"

/**
 * execute - function that executes a command
 * @command: pointer to tokienized command
 * @name: name of the shell
 * @env: pointer to the enviromental variables
 * @i: number of excecution
 */
void execute(char **command, char *name, char **env, int i)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int j = 0;

	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		pathways = _getpath(env);
		while (pathways[j])
		{
			full_path = _strcat(pathways[j], command[0]);
			j++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_cm(pathways);
					free_exit(command);
				}
				return;
			}
		}
		msgerror(name, i, command);
		free_cm(pathways);
		free_exit(command);
	}
}
