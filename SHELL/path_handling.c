#include "shell.h"

int check_command_in_path(const char *command, char *full_path)
{
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL)
    {
        snprintf(full_path, 1024, "%s/%s", token, command);
	_print("Checking: %s\n", full_path);
        if (access(full_path, F_OK) == 0)
            return 1; /* Command found */
        token = strtok(NULL, ":");
    }

    return 0; /* Command not found */
}

void _execute(const char *command, char *args[])
{

    char full_path[1024];
    pid_t child;

    if (!check_command_in_path(command, full_path))
    {
       f _print(stderr, "Error: command %s not found\n", command);
        return;
    }



    if ((child = fork()) == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        if (execve(full_path, args, environ) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;

        waitpid(child, &status, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
        {
            f _print(stderr, "Error: command %s failed to execute\n", command);
        }
    }
}
