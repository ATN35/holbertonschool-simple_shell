#include "shell.h"

int isDirectory(const char *path)
{
	struct stat path_stat;
	if (stat(path, &path_stat) == 0)
	{
		return (S_ISDIR(path_stat.st_mode));
	}
	else
	{
		return (-1);
	}
}
