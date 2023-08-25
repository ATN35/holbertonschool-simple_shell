#include "shell.h"

/**
 * commandNotFound - command not found is replaced by the name of the command
 * @cmd: pointer to a string
 */
void commandNotFound(char *cmd)
{
	fprintf(stderr, "Commande introuvable : %s\n", cmd);
}
/**
 * executionError - indicates an error while executing the command
 * @cmd: pointer to a string
 */

void executionError(char *cmd)
{
	perror(cmd);
}

/**
 * forkError - error message indicates an error creating a new process
 */
void forkError(void)
{
	perror("Erreur lors de la création du processus");
}

/**
 * memoryAllocationError - error message indicates memory allocation error
 */
void memoryAllocationError(void)
{
	perror("Erreur d'allocation de mémoire");
}
