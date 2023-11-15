#include "shell.h"

void exit_shell(void)
{
    printf("Exiting shell...\n");
    exit(EXIT_SUCCESS);
}

void env_shell(void)
{
    char **env_var = environ;

    while (*env_var != NULL)
    {
        printf("%s\n", *env_var);
        env_var++;
    }
}
