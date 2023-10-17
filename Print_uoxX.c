#include "main.h"

/**
 * print_u - Print a unsigned int
 * @args: Number to print
 * Return: Length of the number
 **/

int print_u(va_list args, int flags, int width, int precision, int size)
{
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	char *fstr;
	int s;

	fstr = itac(va_arg(args, unsigned int), 10);

	s = put_string((fstr != NULL) ? fstr : "NULL");

	return (s);
}

/**
 * print_o - Print a unsigned octal
 * @args: Number to print
 * Return: Length of the number
 **/

int print_o(va_list args, int flags, int width, int precision, int size)
{
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	char *fstr;
	int s;

	fstr = itac(va_arg(args, unsigned int), 8);

	s = put_string((fstr != NULL) ? fstr : "NULL");

	return (s);
}

/**
 * print_x- Print a number in hexadecimal format
 * @args: Number to print
 * Return: Length of the number
 **/

int print_x(va_list args, int flags, int width, int precision, int size)
{
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	char *fstr;
	int s;

	fstr = itac(va_arg(args, unsigned int), 16);

	s = put_string((fstr != NULL) ? fstr : "NULL");

	return (s);
}

/**
 * print_X - Print a number in hexadecimal format
 * @args: Number to print
 * Return: Length of the number
 **/

int print_X(va_list args, int flags, int width, int precision, int size)
{
	NO(flags);
	NO(width);
	NO(precision);
	NO(size);

	char *fstr;
	int s;

	fstr = itac(va_arg(args, unsigned int), 16);
	fstr = stou(fstr);

	s = put_string((fstr != NULL) ? fstr : "NULL");

	return (s);
}
