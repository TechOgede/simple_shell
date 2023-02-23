#include "shell.h"

/**
* shell_execute - checks if the command is builtin
* if not it returns launch_prog
* @args: array of strings
* Description: builtin funcs are held
* in structs along with the corresponding commands
* Return: an int
*/

int shell_execute(char **args)
{
	size_t i;
	builtin arr[] = {
			{"exit", shell_exit},
			{"unsetenv", shell_unsetenv},
			{"setenv", shell_setenv},
			{"env", shell_env},
			{"cd", shell_cd}
			};
	if (!args[0])
		return (1);

	for (i = 0; i < sizeof(arr) / sizeof(builtin); i++)
	{
		if (strcmp(args[0], arr[i].cmd) == 0)
			return ((arr[i].func)(args));
	}
	return (launch_prog(args));
}
