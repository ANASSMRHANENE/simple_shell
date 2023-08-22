#include "shell.h"
/**
 * main - the main function
 * Description: the function to switch between shell modes
 * Return: Returns 1 or 0
 */
int main(void)
{
	if (isatty(0) == 1)
	{
		interactive_mode();
	}

	else
	{
		noninteractive_mode();
	}

	return (0);
}
