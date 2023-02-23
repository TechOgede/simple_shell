#include "shell.h"

/**
* shell_get_line - gets input from user
* @argv: pointer to string that holds file name
* @fp: a pointer to a file
* Description: calls the lib func getline and performs error checks
* if argv is NULL, it gets input from stdin
* Return: the buffer
*/

char *shell_get_line(char **argv, FILE *fp)
{
	char *buffer = NULL;
	ssize_t bytes;
	size_t buf_size = 0;

	if (!argv && !fp)
	{
		bytes = getline(&buffer, &buf_size, stdin);
		if (bytes == -2)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
		if (bytes == -1)
			exit(EXIT_FAILURE);
		return (buffer);
	}
	else if (argv && fp)
	{
		bytes = getline(&buffer, &buf_size, fp);
		if (bytes == -2)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
		if (bytes == -1)
			exit(EXIT_FAILURE);
		return (buffer);
	}
	else
		return (NULL);
}
