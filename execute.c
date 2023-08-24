#include "shell.h"

void executeCommand(char *cmd, char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execvp(cmd, args);
		perror("Erreur lors de l'exécution de la commande");
		exit(1);
	}
	else if (pid < 0)
	{
		perror("Erreur lors de la création du processus");
	}
	else
	{
		wait(NULL);
	}
}
