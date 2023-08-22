#include "shell.h"
/**
 * execute_cmd - function to execute commands
 * Description: function that executes commands
 * @agmts: commands entered and their flags
 * Return: Returns 1 or 0
 */
int execute_cmd(char **agmts)
{
	long unsigned int n = 0;
	char *builtin_cmdlist[] = {"exit"};

	int (*builtin_cmd[])(char **) = {&my_exit};

	if (agmts[0] == NULL)
	{
		/*check for empty commands*/
		return (-1);
	}

	/*determine if a command is builtin or not*/
	for (; n < sizeof(builtin_cmdlist) / sizeof(char *); n++)
	{
		/*execute the builtin command*/
		if (strcmp(agmts[0], builtin_cmdlist[n]) == 0)
		{
			return ((*builtin_cmd[n])(agmts));
		}
	}
	/*fork a process*/
	return (exec_pid(agmts));
}
