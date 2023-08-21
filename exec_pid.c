#include "shell.h"
/**
 * exec_pid - function for creating a process
 * @agmts: commands and the options
 * Return: Returns nothing
 */
int exec_pid(char **agmts)
{
	pid_t pid = fork();
	int state;

	if (pid == 0)
	{
		/*check for errors*/
		if (execvp(agmts[0], agmts) == -1)
		{
			perror("Error while creating child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/*check for forking errors*/
		perror("error while forking process");
	}
	else
	{
		while (!WIFEXITED(state) && !WIFSIGNALED(state))
		{
			waitpid(pid, &state, WUNTRACED);
		}
	}
	return (-1);

}
