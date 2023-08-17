#include "shell.h"
/**
 * no_interactive - function to switch the shell to non_interactive mode
 * Return: Returns nothing
 */
void no_interactive(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		/*read from standard input*/
		line = read_file();
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
