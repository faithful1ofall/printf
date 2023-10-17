#include "main.h"

void print_buffer(char lim[], int *j);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, j = 0;
	va_list fargs;
	char lim[1024];

	if (format == NULL)
		return (-1);

	va_start(fargs, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			lim[j++] = format[i];
			if (j == 1024)
				print_buffer(lim, &j);
			printed_chars++;
		}
		else
		{
			print_buffer(lim, &j);
			flags = check_flags(format, &i);
			width = check_width(format, &i, fargs);
			precision = check_precision(format, &i, fargs);
			size = check_size(format, &i);
			++i;
			printed = flag_handler1(format, &i, fargs, lim,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(lim, &j);

	va_end(fargs);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the lim if it exist
 * @lim: Array of chars
 * @j: Index at which to add next char, represents the length.
 */
void print_buffer(char lim[], int *j)
{
	if (*j > 0)
		write(1, &lim[0], *j);

	*j = 0;
}
