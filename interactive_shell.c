#include "shell.h"
/**
 * interactive - function for the shell in interactive mode
 * Description: the function will read commands from stdin
 * Return: Returns nothing
 */
void interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		/*function to print the prompt symbol*/
		printf("shell$");
		/*read from standard input*/
		line = read_cmd();
		args = split_cmd(line);
		status = execute_args(args);
		/*function to prevent memory leaks*/
		free(line);
		free(args);
		/*exit with status*/
		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
