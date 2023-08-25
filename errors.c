#include "shell.h"

void commandNotFound(char *cmd) {
	fprintf(stderr, "Commande introuvable : %s\n", cmd);
}

void executionError(char *cmd) {
	perror(cmd);
}

void forkError(void) {
	perror("Erreur lors de la création du processus");
}

void memoryAllocationError(void) {
	perror("Erreur d'allocation de mémoire");
}
