#include "main.h"
#include <stdarg.h>

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

