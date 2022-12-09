#include "shell.h"

/**
 * main - function that runs our shell.
 * @ac: number of inputed arguments.
 * @av: pointer to array of inputed arguments.
 * @env: pointer to array of enviromental variables.
 * Return: Always 0.
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
			if (_strcmp(command[0], "exit") != 0)
				exitshell(command);
			else if (_strcmp(command[0], "env") != 0)
				print_env(command);
			else
				_fork(command, av[0], env, i);
		}
		fflush(stdin);
		line = NULL, len = 0;
	}
	if (read_line == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
