#include "shell.h"

/**
 **mrset - fills memory
 *@s: pointer
 *@b: byte to fill
 *@n: amount of bytes to be filled
 *Return: pointer to the memory
 */
char *mrset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * sfree - frees a string string
 * @pp: string of strings
 */
void sfree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * re_lloc - reallocate block memory
 * @ptr: pointer
 * @old_size: size previous block
 * @new_size: size new block
 * Return: pointer
 */
void *re_lloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
