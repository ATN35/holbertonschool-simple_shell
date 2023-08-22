#infdef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av, char **env);
pid_t getpid(void);
void prompt(void);


#endif
