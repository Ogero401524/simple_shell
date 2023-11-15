#include "shell.h"

void _print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
