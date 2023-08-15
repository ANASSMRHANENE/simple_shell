#include "shell.h"
/**
 * split_cmd - function to split input string
 * @line: the input string
 * Description: the function that split input string
 * Return: Returns nothing
 */
char **split_cmd(char *line)
{
	int bufsize = 64;
	int i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in split_cmd: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = token;
		i++;

		if (i >= bufsize)
		{
			bufsize += bufsize;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			fprintf(stderr, "reallocation error in split_cmd: tokens\n");
			exit(EXIT_FAILURE);
		}

		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
