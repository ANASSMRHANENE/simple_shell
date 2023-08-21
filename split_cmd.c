#include "shell.h"
/**
 * split_cmd - function to split input string
 * @in_str: the input string
 * Description: the function that split input string
 * Return: Returns nothing
 */
char **split_cmd(char *in_str)
{
	int buffer_size = 64;
	int i = 0;
	char **tkns = malloc(buffer_size * sizeof(char *));
	char *tkn;

	if (!tkns)
	{
		fprintf(stderr, "allocation error in split_cmd: tokens\n");
		exit(EXIT_FAILURE);
	}
	tkn = strtok(in_str, TKN_DELIMITER);
	while (tkn != NULL)
	{
		if (tkn[0] == '#')
		{
			break;
		}
		tkns[i] = tkn;
		i++;

		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
		tkns = realloc(tkns, buffer_size * sizeof(char *));
		if (!tkns)
		{
			fprintf(stderr, "reallocation error in split_cmd: tokens\n");
			exit(EXIT_FAILURE);
		}

		}
		tkn = strtok(NULL, TKN_DELIMITER);
	}
	tkns[i] = NULL;
	return (tkns);
}
