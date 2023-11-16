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
	char commandd[120];

	while (1)
	{
		display_prompt();

		if (fgets(commandd, sizeof(commandd), stdin) == NULL)
		{
			if (feof(stdin))
			{
			_print("\n");
			exit(EXIT_SUCCESS);
			}
			else
			{
				_print("Error in input!\n");
				exit(EXIT_FAILURE);
			}
		}


		commandd[strcspn(commandd, "\n")] = '\0';

		if (strlen(commandd) > 0)
		{
			execute_command(commandd);

		}
	}

	return 0;
}
