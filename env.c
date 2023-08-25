#include "shell.h"

/**
 * printEnvironment - prints the current environment
 * @env: environment
 */
void printEnvironment(char *env[])
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
