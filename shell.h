#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int check_command_in_path(const char *command, char *full_path);
void _execute(const char *command, char *args[]);
void exit_shell(void);
void env_shell(void);

#endif /* SHELL_H */
