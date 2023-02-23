#include "shell.h"

/**
* go_to_prev_dir - returns to the prev dir
* @curr_dir: block of memory used to store cwd
* Description: changes dir to OLDPWD, sets PWD
* Return: an int
*/

int go_to_prev_dir(char *curr_dir)
{
	char *prev;

	getcwd(curr_dir, sizeof(curr_dir));
	prev = curr_dir;
	if (chdir(getenv("OLDPWD")) != 0)
	{
		perror(NULL);
		return (-1);
	}
	setenv("PWD", getenv("OLDPWD"), 1);
	setenv("OLDPWD", prev, 1);
	printf("%s\n", prev);

	return (0);
}

