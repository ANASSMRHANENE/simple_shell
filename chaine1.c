#include "shell.h"

/**
 * lstlen - get length of linked list
 * @h: pointer
 * Return: the size
 */
size_t lstlen(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_strings - return table of strings
 * @head: pointer
 * Return: array
 */
char **list_strings(list_t *head)
{
	list_t *nd = head;
	size_t i = lstlen(head), j;
	char **s;
	char *r;

	if (!head || !i)
		return (NULL);
	s = malloc(sizeof(char *) * (i + 1));
	if (!s)
		return (NULL);
	for (i = 0; nd; nd = nd->next, i++)
	{
		r = malloc(_strlen(nd->r) + 1);
		if (!r)
		{
			for (j = 0; j < i; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}

		r = _strcpy(r, nd->r);
		s[i] = r;
	}
	s[i] = NULL;
	return (s);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
