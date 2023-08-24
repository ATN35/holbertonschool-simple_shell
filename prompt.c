#include "shell.h"

void printPrompt(void) {
	if (isatty(STDIN_FILENO)) {
		printf("$ ");
	}
}
