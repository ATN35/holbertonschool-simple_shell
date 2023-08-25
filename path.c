#include "shell.h"

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
