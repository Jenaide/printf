#include "main.h"
#include <stdarg.h>

/**
 * check_format - checks if there is a valid format specifier
 * @format: valid specifier
 * Return: pointer to function
 */
int (*check_format(const char *format))(va_list)
{
	int x;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"b", print_b},
		{"i", print_i},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (x = 0; p[x].t != NULL; x++)
	{
		if (*(p[x].t) == *format)
			break;
	}
	return (p[x].f);
}

/**
 * _printf - a function that produces output according to a format
 * @format: list of arguments
 * Return: number of characters
 */
int _printf(const char *format, ...)
{
	va_list pip;
	int (*f)(va_list);
	unsigned int x = 0, num = 0;

	if (format == NULL)
		return (-1);

	va_start(pip, format);
	while (format && format[x])
	{
		if (format[x] != '%')
		{
			_putchar(format[x]);
			num++;
			x++;
			continue;
		}
		else
		{
			if (format[x + 1] == '%')
			{
				_putchar('%');
				num++;
				x += 2;
				continue;
			}
			else
			{
				f = check_format(&format[x + 1]);
				if (f == NULL)
					return (-1);
				x += 2;
				num += f(pip);
				continue;
			}
		}
		x++;
	}
	va_end(pip);
	return (num);
}

