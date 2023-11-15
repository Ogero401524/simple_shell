#ifndef SHELLO_H
#define SHELLO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void _print(const char *message);
void display_prompt();
void execute_command(const char *command);

#endif
