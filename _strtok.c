#include "shell.h"

/**
* isdelim - determines if a char is a delmiter
* @c: a character
* @delim: an array of chars that serve as delimiters
*
* Description: compares c with each char of delim
* Return: 1 if c is in delim, 0 if not
*/

int isdelim(char c, char *delim)
{
	int i;

	for (i = 0; delim[i]; i++)
		if (c == delim[i])
			return (1);
	return (0);
}

/**
* _strtok - similar to <string.h> strtok
* @str: string to be tokenized
* @delim: string of chars used as delimiters
*
* Description: Finds the delim char in str and writes in
* a '\0'. For other calls, str should be NULL as the function
* uses a static pointer to hold the rest of str
* Return: a token is returned on each call. NULL is returned when
* str can no longer be tokenized.
*/

char *_strtok(char *str, char *delim)
{
	static char *rest;
	char *ret;

	if (!delim)
		return (NULL);
	if (!str)
		str = rest;
	if (!str)
		return (NULL);
	while (1)
	{
		if (isdelim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}
	ret = str;
	while (1)
	{
		if (*str == '\0')
		{
			rest = str;
			return (ret);
		}
		if (isdelim(*str, delim))
		{
			*str = '\0';
			rest = str + 1;
			return (ret);
		}
		str++;
	}


}
