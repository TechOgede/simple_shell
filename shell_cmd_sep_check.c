#include "shell.h"

/**
* shell_cmd_sep_check - checks for a command seperator
* @line: string gotten from user
* @seps: a string of chars used as separators
*
* Description: simply loops through the line input from the user
* checking for the seperator char
* Return: 1 if found, 0 otherwise
*/

int shell_cmd_sep_check(char *line, char *seps)
{
	int i;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == *seps)
			return (1);
	}
	return (0);
}
