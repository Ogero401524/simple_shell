#include "shell.h"
/**
 * main - Entry point for the simple shell program
 *
 * This function serves as the entry point for the simple shell program.
 * It displays a prompt, reads user input, and executes the specified
 * command until the user exits the shell.
 *
 * Return: Always returns 0.
 */

int main()
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();

		if (fgets(command, sizeof(command), stdin) == NULL)
		{

			_print("\nExiting shell...\n");
			break;
		}


		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) > 0)
		{
			execute_command(command);
		}
	}

	return 0;
}
