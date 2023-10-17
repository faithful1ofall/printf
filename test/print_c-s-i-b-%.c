#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_c - Prints a char
 * @args: List a of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_c(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (write_c(c, lim, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_s - Prints a string
 * @args: List a of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_s(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	NO(lim);
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & C_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @args: Lista of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	NO(args);
	NO(lim);
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_i_d - Print int
 * @args: Lista of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_i_d(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	int i = 1024 - 2;
	int negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = conv_size_numb(n, size);

	if (n == 0)
		lim[i--] = '0';

	lim[1024 - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}

	while (num > 0)
	{
		lim[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_fnumb(negative, i, lim, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_b - Prints an unsigned number
 * @args: Lista of arguments
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_b(va_list args, char lim[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	NO(lim);
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
