#include "shell.h"

/**
* shell_comment_check - checks if the user entered a comment
* @line: user string input
*
* Description: checks for the comment char '#'.
* If found, it writes a null char its place.
* Return: the modified string or the original input
*/

char *shell_comment_check(char *line)
{
	int i;

	for (i = 0; line[i]; i++)
	{
		if (line[i] == '#')
		{
			line[i] = '\0';
			return (line);
		}
	}
	return (line);

}
