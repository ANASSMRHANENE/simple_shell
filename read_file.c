#include "shell.h"

/**
 * read_file - read a line from the file
 * Return: pointer that points the the read line
 */
char *read_stream(void)
{
int bufs = 1024;
int i = 0;
char *line = malloc(sizeof(char) * bufs);
int charr;
if (line == NULL)
{
fprintf(stderr, "allocation error in read_stream");
exit(EXIT_FAILURE);
}
while (1)
{
charr = getchar(); /* read first char from stream */
if (charr == EOF)
{
free(line);
exit(EXIT_SUCCESS);
}
else if (charr == '\n')
{
line[i] = '\0';
return (line);
}
else
{
line[i] = charr;
}
i++;
if (i >= bufs)
{
bufs += bufs;
line = realloc(line, bufs);
if (line == NULL)
{
fprintf(stderr, "reallocation error in read_stream");
exit(EXIT_FAILURE);
}
}
}
}
