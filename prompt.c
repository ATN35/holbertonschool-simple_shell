#include "shell.h"

/**
 * printPrompt -  prints the shell prompt
*/
void printPrompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}
}
