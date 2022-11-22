#include "main.h"

/**
 * print_c - function that prints a char
 * @c: char type
 * Return: 1 on success
 */
int print_c(va_list c)
{
	char function = (char)va_arg(c, int);

	_putchar(function);
	return (1);
}
