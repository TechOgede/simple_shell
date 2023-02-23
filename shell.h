#ifndef SHELL_H
#define SHELL_H

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<fcntl.h>
extern char **environ;

/**
* struct builtin - a struct of commands built into the shell
* @cmd: a string that denotes the command
* @func: a pointer to a function
*
* Description: The struct would be accessed
* cmd would be conmpared with the user's command
*/

typedef struct builtin
{
	char *cmd;
	int (*func)(char **args);
} builtin;

void shell_prompt(void);
char *shell_get_line(char **argvi, FILE *fp);
int shell_cmd_sep_check(char *line, char *seps);
char **shell_parse_line(char *line);
int shell_execute(char **args);
int launch_prog(char **args);
char **shell_get_dirs(void);
char *shell_get_command(char **args, char **dirs);
ssize_t _getline(char **line, size_t *len, int fd);
void shell_free_exit(int status, char *line, char **args);
char *shell_comment_check(char *line);
int shell_check_file(int argc, char **argv);
char **shell_dup_env(void);
int _unsetenv(char *name);

/* shell_builtins*/
int shell_exit(char **args);
int shell_env(__attribute__((unused)) char **args);
int shell_setenv(char **args);
int shell_unsetenv(char **args);
int shell_cd(char **args);
int go_to_named_dir(char *curr_dir, char *args);
int go_to_home_dir(char *curr_dir);
int go_to_prev_dir(char *curr_dir);

/* for _strtok*/
int isdelim(char c, char *delim);
char *_strtok(char *str, char *delim);


#endif
