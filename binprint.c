#include "main.h"

/**
 * print_binary - Print a number in base 2
 * @args: Number to print in base 2
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * Return: Length of the numbers in binary
 **/
int print_binary(va_list args, int flags, int width, int precision, int size, char lim[])
{
	char *fstr;
	int s;

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);
	NO(lim);

	fstr = itac(va_arg(args, unsigned int), 2);

	s = put_string(fstr);

	return (s);
}
