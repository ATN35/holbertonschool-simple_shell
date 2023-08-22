#include "shell.h"

/**
 * _EOF - function that chaecks if line is EOF
 * @line: pointer to the input string
 */
void _EOF(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(line);
	exit(EXIT_SUCCESS);
}
