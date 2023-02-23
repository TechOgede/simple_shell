#include "shell.h"


/**
* shell_unsetenv - removes an environment variable
* @args: array of strings
*
* Description: looks through the environ arraym
* finds the variable and removes it by pushing
* successive entries back one element
*
* Return: 0 on success, -1 on error
*/

int shell_unsetenv(char **args)
{
	char *name = args[1], **ep, **sp;
	size_t len = strlen(name), args_len = 0;

	for (args_len = 0; args[args_len]; args_len++)
		;
	if (args_len != 2)
	{
		errno = EINVAL;
		perror("Usage: unsetenv [variable]\n");
		return (-1);
	}

	for (ep = environ; *ep; ep++)
	{
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
			for (sp = ep; *sp; sp++)
				*sp = *(sp + 1);
	}
	return (0);
}



/**
* shell_setenv - creates a new environment var
* or modifies a new one.
* @args: array of strings
*
* Description: creates a string 72Gin the format 'name=value'
* and passes that string to putenv
* Return: 0 if successful. -1 on error
*/

int shell_setenv(char **args)
{
	char *name = args[1], *value = args[2], *new_entry;
	int ret, args_len;

	for (args_len = 0; args[args_len]; args_len++)
		;
	if (args_len != 3)
	{
		errno = EINVAL;
		perror("Usage: setenv [variable] [value]\n");
		return (-1);
	}
	if (name == NULL || value == NULL)
	{
		errno = EINVAL;
		perror(NULL);
		return (-1);
	}
	if (getenv(name)) /*if the variable exists in environ, unset it */
		_unsetenv(name);
	new_entry = malloc(strlen(name) + strlen(value) + 2);
	if (!new_entry)
	{
		perror(NULL);
		return (-1);
	}
	strcpy(new_entry, name);
	strcat(new_entry, "=");
	strcat(new_entry, value);
	ret = putenv(new_entry);
	if (ret)
	{
		perror(NULL);
		return (-1);
	}
	return (0);
}
/**
* shell_env - prints the environment
* @args: array of strings
* Description: uses the environ var
* Return: 1 if successful
*/
int shell_env(__attribute__((unused)) char **args)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return (1);
}


/**
* shell_cd - change directory
* @args: array of strings
*
* Description: takes a pathname and calls chdir
* Return: 1 if successful
*/

int shell_cd(char **args)
{
	char *curr_dir;
	int args_len;

	for (args_len = 0; args[args_len]; args_len++)
		;
	if (args_len != 2 && args_len != 1)
	{
		errno = EINVAL;
		perror("Usage: cd [Directory]\n");
		return (-1);
	}
	curr_dir = malloc(sizeof(char) * 1024);
	if (!curr_dir)
	{
		perror(NULL);
		return (-1);
	}
	if (args_len == 1)
	{
		go_to_home_dir(curr_dir);
		free(curr_dir);
		return (0);
	}
	if (strcmp(args[1], "-") == 0)
	{
		go_to_prev_dir(curr_dir);
		free(curr_dir);
		return (0);
	}

	else
	{
		go_to_named_dir(curr_dir, args[1]);
		free(curr_dir);
		return (0);
	}
	return (0);
}


/**
* shell_exit - exits the shell program
* @args: array of strings
* Description: simply calls exit()
* Return: exits with 0
*/

int shell_exit(char **args)
{
	int status, args_len;

	for (args_len = 0; args[args_len]; args_len++)
		;
	if (args_len != 1 && args_len != 2)
	{
		errno = EINVAL;
		perror("Usage: exit or exit [integer]\n");
		return (6999);
	}

	if (args_len == 1)
		return (6990);

	status = atoi(args[1]);

	if (args_len == 2)
		return (status);
	return (0);

}
