#include "shell.h"

char **getPath(void)
{
	char *path = getenv("PATH");
	if (path == NULL)
	{
		perror("Erreur lors de la récupération du chemin PATH");
		exit(1);
	}

	return (NULL);
}
