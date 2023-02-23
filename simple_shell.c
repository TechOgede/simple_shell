#include "shell.h"

/**
* shell_prompt - prints a char to prompt user to enter command
* Description: prints the shell prompt
* Return: no return value
*/

void shell_prompt(void)
{
	char prompt[9] = "#cisfun$ ";
	int err;

	err = write(STDOUT_FILENO, &prompt, 9);
	if (err == -1)
	{
		perror("Error: Shell cannot be initialized");
		exit(EXIT_FAILURE);
	}

}


/**
* main - Entry point to shell
* @argc: num of CL args
* @argv: array of CL args
*
* Description: displays a prompt, gets input from user,
* handles the command seperator ';',
* parses the user's input and executes the commands
* Return: 0 if successful, anything else otherwise
*/

int main(int argc, char **argv)
{
	char *line, **args, *command;
	int cmd_sep, term_mode, status, file_mode = 0;
	FILE *fp;

	term_mode = isatty(STDIN_FILENO);
	file_mode = shell_check_file(argc, argv);
	fp = fopen(argv[1], "r");
	if (file_mode)
		term_mode = 0;
	while (1)
	{
		if (term_mode)
		{
			shell_prompt();
			line = shell_get_line(NULL, NULL);
		}
		if (file_mode)
			line = shell_get_line(argv, fp);
		line = shell_comment_check(line);
		cmd_sep = shell_cmd_sep_check(line, ";");
		if (cmd_sep)
		{
			command = _strtok(line, ";");
			while (command)
			{
				args = shell_parse_line(command);
				status = shell_execute(args);
				command = _strtok(NULL, ";");
			}
		}
		else
		{
			args = shell_parse_line(line);
			status = shell_execute(args);
		}
		shell_free_exit(status, line, args);
	}


	return (0);
}
