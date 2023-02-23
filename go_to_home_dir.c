#include "shell.h"

/**
* go_to_home_dir - changes dir to home dir
* @curr_dir: block of memory to store the cwd
*
* Description: stores cwd, goes to home, changes the value
* of OLDPWD to cwd and frees curr_dir
* Return: an int
*/

int go_to_home_dir(char *curr_dir)
{

	getcwd(curr_dir, sizeof(curr_dir));
	if (chdir(getenv("HOME")) != 0)
	{
		perror(NULL);
		return (-1);
	}
	setenv("PWD", getenv("HOME"), 1);
	setenv("OLDPWD", curr_dir, 1);

	return (0);

}
