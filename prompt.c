#include "shell.h"

/**
 * prompt - fonction that print the prompt
 */
void prompt(void)
{
	if (isatty(SDTIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
