#include "shell.h"

extern char **environ;

/**
 * execute_command - Execute a command using fork and execve
 * @command: The command to execute
 *
 * This function creates a child process using fork and attempts
 * to execute the specified command using execve. It prints an
 * error message if the command is not found.
 *
 * Return: No return value.
 */
void execute_command(const char *command)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		char *args[2];
		args[0] = strdup(command);
		args[1] = NULL;

		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
	int status;
	waitpid(child, &status, 0);
	}
}
