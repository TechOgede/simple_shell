#include "shell.h"

/**
* shell_dup_env - duplicates the enviornment variable
*
* Description: copies the env var into allocated memory
* Return: a pointer to the copy of the env var
*/

char **shell_dup_env(void)
{
	char **child_env;
	int i;

	for  (i = 0; environ[i]; i++)
		;
	child_env = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
	child_env[i] = strdup(environ[i]);
	child_env[i++] = NULL;

	return (child_env);
}
