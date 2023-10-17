#include "main.h"

/**
 * print_binary - Print a number in base 2
 * @args: Number to print in base 2
 * Return: Length of the numbers in binary
 **/
int print_binary(va_list args, int flags, int width, int precision, int size)
{
	char *fstr;
	int s;

	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	fstr = itac(va_arg(args, unsigned int), 2);

	s = put_string(fstr);

	return (s);
}
