#include "shell.h"
/**
 * my_exit - function that exits the shell
 * @agmts: arguments
 * Return: returns 1 or 0
 */
int my_exit(char **agmts)
{
	if (agmts[1] != NULL)
	{
		int exit_code = atoi(agmts[1]);

		printf("exitig with code: %d\n", exit_code);
		exit(exit_code);
	}
	else
	{
		printf("Usage: my_exit <exit_code>\n");
		return (1);
	}
}
