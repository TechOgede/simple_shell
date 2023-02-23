#include "shell.h"

/**
* shell_parse_line - parses the line to get the
* command options and arguments if given
* @line: buffer with contents
*
* Description: parses the contents of the buffer
* into tokens and stores them in an array
* Return: array of strings
*/

char **shell_parse_line(char *line)
{
	char **args, *token, *sep = " \n";
	int pos = 0;

	args = malloc(sizeof(char *) * 32);
	if (!args)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, sep);
	args[pos] = token;

	while (token)
	{
		pos++;
		token = strtok(NULL, sep);
		args[pos] = token;
	}
	args[pos++] = NULL;
	return (args);
}
