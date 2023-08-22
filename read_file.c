#include "shell.h"
/**
 * read_file - function that reads input from a file
 * Return: returns a pointer to the file content
 */
char *read_file(void)
{
	int buffer_size = 1024;
	int i = 0;
	char *in_str = malloc(sizeof(char) * buffer_size);
	int ch;

	if (in_str == NULL)
	{
		fprintf(stderr, "allocation error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		/*read file content*/
		ch = getchar();
		if (ch == EOF)
		{
			free(in_str);
			exit(EXIT_SUCCESS);
		}
		else if (ch == '\n')
		{
			in_str[i] = '\0';
			return (in_str);
		}
		else
		{
			in_str[i] = ch;
		}
		i++;
		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
			in_str = realloc(in_str, buffer_size);
			if (in_str == NULL)
			{
				fprintf(stderr, "reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
