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

		char *args[ARG_MAX];
		char *token = strtok((char *)command, " ");
		int i = 0;


		while (token != NULL && i < ARG_MAX - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;


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
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			_print("./shell: No such file or directory\n");
		}
	}
}
