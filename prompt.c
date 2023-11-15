#include "shell.h"
/**
 * _print - Print a message to the standard output
 * @message: The message to print
 *
 * This function writes the specified message to the standard output.
 *
 * Return: No return value.
 */
void _print(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}

/**
 * display_prompt - Display a simple shell prompt
 *
 * This function displays a simple shell prompt to the standard output.
 *
 * Return: No return value.
 */
void display_prompt()
{
	_print("#%$ ");
}
