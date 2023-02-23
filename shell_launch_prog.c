#include "shell.h"

/**
* launch_prog - executes programs
* @args: an array of strings
*
* Description: creates a child process to execute the program
* and checks for errors
* Return: 1 if successful, o if not
*/

int launch_prog(char **args)
{
	pid_t pid;
	int i, err, status;
	char **dirs, *command, **child_env;

	dirs = shell_get_dirs();
	command = shell_get_command(args, dirs);
	free(dirs);
	if (command)
	{
		child_env = shell_dup_env();

		args[0] = command;

		pid = fork();
		if (pid == 0)
		{
			err = execve(command, args, child_env);
			if (err < 0)
			{
				perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
			perror(NULL);
		else
		{
			wait(&status);
		}
		for (i = 0; child_env[i]; i++)
			free(child_env[i]);
		free(child_env);
	}
	free(command);
	return (1);
}
