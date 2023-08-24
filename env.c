#include "shell.h"

void printEnvironment(char *env[])
{
	int i;
	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
