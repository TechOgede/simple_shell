#include "shell.h"

/**
* shell_free_exit - frees memory when the exit builtin is called
* @status: an int denoting the status code to exit with
* @line: user's input or commands gotten from a file
* @args: array of the tokens gotten from line
*
* Description: frees 'line' and 'args' memory block and exits
* Return: no return value
*/

void shell_free_exit(int status, char *line, char **args)
{
	free(line);
	free(args);

	if (status == 6990)
		exit(0);
	if (status != 6999 && status != 0 && status != 1)
		exit(status);
}
