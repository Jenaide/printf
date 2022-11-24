#include "main.h"

/*** print characters ***/

/**
 * print_char - print chars
 * @types: a list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: the width
 * @precision: precision
 * @size: size of specifier
 * Return: chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/************prints a string**********/

/**
 * print_string - prints a string
 * @type: list of arguments
 * @buffer: buffer array
 * @flags: clac active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 * Return: chars to be printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int length = 0, x;
	char *string = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}

	while (string[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], length);
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
		}
	}
	return (write(1, string, length));
}

/********** prints the % sign***********/

/**
 * print_precent - prints the percent sign
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: chars to be printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************** print integer ******************/

/**
 * print_int - print integer
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: calc active flags
 * @width: width
 * @precision: precision specs
 * @size: size specifier
 * Return: chars to be printed
 */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	long int a = va_arg(types, long int);
	unsigned long int num;
	int z = BUFF_SIZE - 2;
	int is_negative = 0;

	a = convert_size_number(a, size);

	if (a == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)a;

	if (a < 0)
	{
		num = (unsigned long int) ((-1) * a);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[z--] = (num % 10) + '0';
		num /= 10;
	}

	z++;

	return (write_number(is_negative, z, buffer, flags, width, precision, size));
}

/***************prints the binary******************/

/**
 * print_binary - function that prints an unsigned num
 * @types: lsit of arguments
 * @buffer: buffer array
 * flags: clac active flags
 * width: width
 * @precision: precision specs
 * @size: size spec
 * Return: chars to be printed
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int cnt;
	unsigned int z, x, v, sum;
	unsigned int a[32];

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	z = va_arg(types, unsigned int);
	x = 2147483648;
	a[0] = z / x;
	for (v = 1; v < 32; v++)
	{
		x /= 2;
		a[v] = (z / x) % 2;
	}
	for (v = 0, sum = 0, cnt = 0; v < 32; v++)
	{
		sum += a[v];
		if (sum || v == 31)
		{
			char d = '0' + a[v];

			write(1, &d, 1);
			cnt++;
		}
	}
	return (cnt);
}
