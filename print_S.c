#include "main.h"
#include <stdlib.h>

/**
 * print_S - function that prints a string and nonprinteable
 * char ascii values
 * @S: string
 * Return: number of chars
 */
int print_S(va_list S)
{
	int ctr;
	unsigned int x;
	char *string = va_arg(S, char *);

	if (string == NULL)
		string = "(null)";
	for (x = 0; string[x]; x++)
	{
		if (string[x] < 32 || string[x] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			ctr += 2;
			ctr += print_x(S);
		}
		else
		{
			_putchar(string[x]);
			ctr++;
		}
	}
	return (ctr);
}
