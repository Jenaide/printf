#include "main.h"
#include <unistd.h>

/**
 * print_s - function that prints a string
 * @s: string format
 * Return: x
 */
int print_s(va_list s)
{
	char *string = va_arg(s, char *);
	int x = 0;

	if (string == NULL)
		string = "(null)";
	while (string[x])
		_putchar(str[x++]);
	return (x);
}
