#include "shell.h"
/**
 * read_cmd - function to read commands from the stdin
 * Description: the function will read user entered commands
 * Return: pointer
 */
char *read_cmd(void)
{
	char *in_str = NULL;
	size_t buffer_size = 0;

	/*incase of failure of getline*/
	if (getline(&in_str, &buffer_size, stdin) == -1)
	{
		/*test for end of file*/
		if (feof(stdin))
		{
			/*prevent memory leaks*/
			free(in_str);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/*prevent memory leaks*/
			free(in_str);
			perror("error while reading from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (in_str);
}
