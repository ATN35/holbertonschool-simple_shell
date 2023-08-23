#include "shell.h"

/**
 * _getpath - function to get the list of paths from PATH environment variable
 * Return: an array of pointers to paths
 */
char **_getpath(void)
{
	char *pathvalue = getenv("PATH");

	if (pathvalue == NULL)
		return (NULL);

	return (tokenize(pathvalue, ":"));
}
