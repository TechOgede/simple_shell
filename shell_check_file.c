#include "shell.h"

/**
* shell_check_file - checks the cmd line args passed to the shell
* @argc: num of cmd line args
* @argv: array holding the cmd line args
*
* Description: checks for appropriate usage and errors
* Return: 1 if shell is called with a file correctly and file exists
*/

int shell_check_file(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc != 2)
	{
		perror("Usage: shell_name [filename]\n");
		exit(EXIT_FAILURE);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	return (1);
}
