#include "shell.h"

/**
* go_to_named_dir - go to a named dir provided by the user
* @args: user's input that could be a name of a dir or a denoting symbol21Gi
* @curr_dir: a buffer to store the current directory
*
* Description: uses chdir to go to the directory
* Return: no return value
*/

int go_to_named_dir(char *curr_dir, char *args)
{
	getcwd(curr_dir, sizeof(curr_dir));
	if (chdir(args) != 0)
	{
		getcwd(curr_dir, sizeof(curr_dir));
		perror(NULL);
		return (-1);
	}
	setenv("PWD", args, 1);
	setenv("OLDPWD", curr_dir, 1);

	return (0);
}
