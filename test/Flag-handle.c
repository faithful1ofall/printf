#include "main.h"

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * @lim:  array to handle print
 * Return: Number of chars printed
 */

int print_percent(va_list args, int flags, int width, int precision,
int size, char lim[])
{
	NO(args);
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	NO(lim);
	return (write(1, "%%", 1));
}

/**
 * flag_handler1 - Controller for percent format
 * @str: String format
 * @args: List of arguments
 * @i: Iterator
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * @lim: character array
 * Return: Size of the numbers of elements printed
 **/

int flag_handler1(const char *str, va_list args, int *i,
char lim[], int flags, int width, int precision, int size)
{
	int j, unlen = 0;
	form formats[] = {
		{'s', print_string}, {'c', print_char}, {'d', print_integer},
		{'i', print_integer}, {'b', print_binary}, {'u', print_u},
		{'%', print_percent},{'o', print_o}, {'x', print_x},
		{'X', print_X}, {'p', print_p}, {'S', print_S},
		{'r', print_r}, {'R', print_R}, {'\0', NULL}
	};
	/* if (str[*i] == '%')
	{
		put_char('%');
		return (1);
	} */
	for (j = 0; formats[j].typ != '\0'; j++)
		if (str[*i] == formats[j].typ)
			return (formats[j].fa(args, flags, width, precision, size, lim));
	
	if (formats[j].typ == '\0')
	{
		if (str[*i] == '\0')
			return (-1);
		unlen += write(1, "%%", 1);
		if (str[*i - 1] == ' ')
			unlen += write(1, " ", 1);
		else if (width)
		{
			--(*i);
			while (str[*i] != ' ' && str[*i] != '%')
				--(*i);
			if (str[*i] == ' ')
				--(*i);
			return (1);
		}
		unlen += write(1, &str[*i], 1);
		return (unlen);
	}
	return (-1);
}
