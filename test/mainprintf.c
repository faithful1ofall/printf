#include "main.h"

void print_buffer(char lim[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list fargs;
	char lim[1024];

	if (format == NULL)
		return (-1);

	va_start(fargs, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			lim[buff_ind++] = format[i];
			if (buff_ind == 1024)
				print_buffer(lim, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(lim, &buff_ind);
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

	print_buffer(lim, &buff_ind);

	va_end(fargs);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the lim if it exist
 * @lim: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char lim[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &lim[0], *buff_ind);

	*buff_ind = 0;
}
