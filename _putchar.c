#include <unistd.h>

/**
 * _putchar - writes the char c to stdout
 * @c: character to be printed
 * Return: 1 on success or -1 if error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
