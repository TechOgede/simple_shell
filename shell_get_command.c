#include "shell.h"

/**
* shell_get_command - executes program in a child process
* @args: array of strings gotten from the user
* @dirs: array of dirs gotten from getcwd and PATH
*
* Description: checks for the command's existence
* in any of the dirs and if found it executes
* Return: returns a path to the command or NULL if command isnt found
*/

char *shell_get_command(char **args, char **dirs)
{
	char *buf;
	int i;

	if (args[0][0] == '/')
	{
		if (access(args[0], F_OK) == 0)
		{
			return (args[0]);
		}
	}
	else
	{
		buf = malloc(sizeof(char) * 150);
		for (i = 0; dirs[i]; i++)
		{
			strcpy(buf, dirs[i]);
			strcat(buf, "/");
			strcat(buf, args[0]);
			strcat(buf, "\0");
			if (access(buf, F_OK) == 0)
			{
				return (buf);
			}
		}
	}
	perror(args[0]);

	return (NULL);
}

