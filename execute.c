#include "shell.h"
/**
 * execute_cmd - function to execute commands
 * Description: function that executes commands
 * @agmts: commands entered and their flags
 * Return: Returns 1 or 0
 */
int execute_cmd(char **agmts)
{
	int i = 0;
	char *builtin_cmdlist[] = {"exit", "help", "env", "cd"};

	int (*builtin_cmd[])(char **) = {&my_exit, &my_help, &my_env, &my_cd};

	if (agmts[0] == NULL)
	{
		/*check for empty commands*/
		return (-1);
	}

	/*determine if a command is builtin or not*/
	for (; i < (int)(sizeof(builtin_cmdlist) / sizeof(char *)); i++)
	{
		/*execute the builtin command*/
		if (strcmp(agmts[0], builtin_cmdlist[i]) == 0)
		{
			return ((*builtin_cmd[i])(agmts));
		}
	}
	/*fork a process*/
	return (exec_pid(agmts));
}
