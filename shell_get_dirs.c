#include "shell.h"

/**
* shell_get_dirs - Creates an array of dirs
*
* Description: creates an array of dirs found in PATH.
* The cwd is also included in the array
* Return: array of strings
*/

char **shell_get_dirs(void)
{
	char cwd[1024], path[1024], *tkn, **dirs, *wd;
	int i = 0;

	wd = getcwd(cwd, 1024);
	strcpy(path, getenv("PATH"));
	dirs = malloc(sizeof(char *) * 32);
	dirs[i] = wd;
	tkn = strtok(path, ":");
	i++;
	dirs[i] = tkn;
	while (tkn)
	{
		tkn = strtok(NULL, ":");
		i++;
		dirs[i] = tkn;
	}
	i++;
	dirs[i] = NULL;
	return (dirs);
}
