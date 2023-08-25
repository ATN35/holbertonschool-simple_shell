#include "shell.h"

/**
 * getPath - that retrieves the paths from the environment variable PATH
 * and returns them as an array
 * Return: Nothing
 */
char **getPath(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		memoryAllocationError();
		exit(1);
	}

	return (NULL);
}
