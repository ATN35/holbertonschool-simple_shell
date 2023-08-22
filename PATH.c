#include "shell.h"

/**
 * _getpath - function to get the list of paths from PATH environment variable
 * @env: pointer to environmental variables
 * Return: an array of pointers to paths
 */
char **_getpath(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		if (_strcmp(env[i], "PATH") == 0)
		{
			pathvalue = strtok(env[i + 1], "=");

			pathways = tokenize(pathvalue, ":");

			return (pathways);
		}
		i++;
	}
	return (NULL);
}
