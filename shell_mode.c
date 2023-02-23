#include "shell.h"

/**
* shell_mode - determines the mode to boot the shell getline in
* @file_mode: int denoting if shell is to get input from a file
* @term_mode: int denoting if shell is to get input from stdin
* @fp: a pointer to a file
* Description: uses some conditional statments
* Return: a string of input
*/

char *shell_mode(int file_mode, int term_mode, FILE *fp)
{
	char *line;

		if ((!file_mode && !term_mode) || term_mode)
			line = shell_get_line(NULL, NULL);
		if (file_mode && !term_mode)
			line = shell_get_line(NULL, fp);

		return (line);
}
