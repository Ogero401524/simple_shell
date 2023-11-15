#include "shell.h"
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
extern char **environ;

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

		if (execve(command, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		free(args[0]);
	}
	else
	{
		int status;
		waitpid(child, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			_print("./shell: No such file or directory\n");
		}
	}
}
