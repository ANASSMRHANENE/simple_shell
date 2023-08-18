#include "shell.h"
/**
 * execute_args - function to execute commands
 * Description: function that executes commands
 * @args: commands entered and their flags
 * Return: Returns 1 or 0
 */
int execute_args(char **args)
{
	long unsigned int i = 0;
	char *builtin_func_list[] = {"cd", "env", "help", "exit"};

	int (*builtin_func[])(char **) = {&own_cd, &own_env, &own_help, &own_exit};

	if (args[0] == NULL)
	{
		/*empty command was entered*/
		return (-1);
	}

	/*find whether command is builtin*/
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		/*compare and execute the builtin command*/
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	/*create a new process*/
	return (new_process(args));
}
