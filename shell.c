#include "shell.h"
/**
 * interactive_mode - function for the shell in interactive mode
 * Description: the function will read commands from stdin
 * Return: Returns nothing
 */
void interactive_mode(void)
{
	char *in_str;
	char **agmts;
	int state = -1;

	do {
		/*function to print the shell prompt*/
		printf("shell$");
		/*read from standard input*/
		in_str = read_cmd();
		agmts = split_cmd(in_str);
		state = execute_cmd(agmts);
		/*function to prevent memory leaks*/
		free(in_str);
		free(agmts);
		/*exit with state*/
		if (state >= 0)
		{
			exit(state);
		}
	} while (state == -1);
}
/**
 * noninteractive_mode - function to switch the shell to non-interactive mode
 * Return: Returns nothing
 */
void noninteractive_mode(void)
{
	char *in_str;
	char **agmts;
	int state = -1;

	do {
		/*read from file*/
		in_str = read_file();
		agmts = split_cmd(in_str);
		state = execute_cmd(agmts);
		/*function to prevent memory leaks*/
		free(in_str);
		free(agmts);
		/*exit with state*/
		if (state >= 0)
		{
			exit(state);
		}

	} while (state == -1);
}
