#include "shell.h"
/**
 * read_cmd - function to read commands from the stdin
 * Description: the function will read user entered commands
 * Return: Returns nothing
 */
char read_cmd(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	/*incase of failure of getline*/
	if (getline(&line, &bufsize, stdin) == -1)
	{
		/*test for end of file*/
		if (feof(stdin))
		{
			/*prevent memory leaks*/
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/*prevent memory leaks*/
			free(line);
			perror("error while reading from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
