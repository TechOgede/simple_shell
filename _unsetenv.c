#include "shell.h"


/**
* _unsetenv - removes an environment variable
* @name: name of env variable to unset
*
* Description: looks through the environ arraym
* finds the variable and removes it by pushing
* successive entries back one element
*
* Return: 0 on success, -1 on error
*/

int _unsetenv(char *name)
{
	char **ep, **sp;
	size_t len = strlen(name);

	for (ep = environ; *ep; ep++)
	{
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=')
			for (sp = ep; *sp; sp++)
				*sp = *(sp + 1);
	}
	return (0);
}

