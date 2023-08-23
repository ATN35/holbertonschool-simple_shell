#include "shell.h"

/**
 * _getpath - function to get the list of paths from PATH environment variable
 * @env: pointer to environmental variables
 * Return: an array of pointers to paths
 */
char **_getpath(char **env)
{
	char *pathvalue = getenv("PATH");

	if (pathvalue == NULL)
		return (NULL);

	return (tokenize(pathvalue, ":"));
}
