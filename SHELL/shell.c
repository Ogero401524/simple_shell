#include "shell.h"

int main(void)
{
    char *user_input = NULL;
    size_t input_length = 0;
    ssize_t chars_read;

    while (1)
    {
        _print("$ ");
        fflush(stdout);

        chars_read = getline(&user_input, &input_length, stdin);

        if (chars_read == -1)
        {
            if (feof(stdin))
            {
                _print("\n");
                exit_shell();
            }
            else
            {
                perror("getline");
                exit(EXIT_FAILURE);
            }
        }

        if (chars_read > 0 && user_input[chars_read - 1] == '\n')
        {
            user_input[chars_read - 1] = '\0';
        }

        if (user_input[0] != '\0')
        {
            char *token = strtok(user_input, " ");
            char *args[32];
            int arg_count = 0;

            while (token != NULL && arg_count < 31)
            {
                args[arg_count++] = token;
                token = strtok(NULL, " ");
            }

            args[arg_count] = NULL;

            if (strcmp(args[0], "exit") == 0)
            {
                exit_shell();
            }
            else if (strcmp(args[0], "env") == 0)
            {
                env_shell();
            }
            else
            {
                _execute(args[0], args);
            }
        }
    }

    free(user_input);
    return 0;
}
