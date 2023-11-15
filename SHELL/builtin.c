#include "shell.h"

void exit_shell(void)
{
    _print("Exiting shell...\n");
    exit(EXIT_SUCCESS);
}

void env_shell(void)
{
    char **env_var = environ;

    while (*env_var != NULL)
    {
        _print("%s\n", *env_var);
        env_var++;
    }
}
