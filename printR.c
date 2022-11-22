#include "main.h"
#include <stdlib.h>

/**
 * print_R - function that prints a string in rot13 format
 * @R: string format
 * Return: number of chars
 */
int print_R(va_list R)
{
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *string;
	int ctr;
	unsigned int z, x;

	string = va_arg(R, char *);
	if (string == NULL)
		string = "(hello)";
	for (z = 0; string[z]; z++)
	{
		for (x = 0; in[x]; x++)
		{
			if (in[x] == string[z])
			{
				_putchar(out[x]);
				ctr++;
				break;
			}
		}
		if (!in[x])
		{
			_putchar(string[x]);
			ctr++;
		}
	}
	return (ctr);
}
