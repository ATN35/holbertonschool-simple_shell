#include "shell.h"

/**
 * main - shell entry point
 * @ac: number of input arguments
 * @av: array of input arguments
 * @env: array of environmental variables
 * Return: always 0
 */
int main(int ac, char **av, char **env)
{
	char *line = NULL, **command = NULL;
	size_t len = 0;
	ssize_t read_line = 0;
	int i = 0;

	(void)ac;

	while (1)
	{
		i++;
		prompt();

		read_line = getline(&line, &len, stdin);
		if (read_line == EOF)
			_EOF(line);
		else if (*line == '\n')
			free(line);
		else
		{
			line[_strlen(line) - 1] = '\0';
			command = tokenize(line, " \0");
			free(line);

			if (_strcmp(command[0], "exit") == 0)
				exitshell(command);
			else if (_strcmp(command[0], "env") == 0)
				print_env(command);
			else
				_fork(command, av[0], env, i);

			free_tokens(command);
		}

		line = NULL, len = 0;
	}

	if (read_line == -1)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
