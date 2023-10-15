#include "main.h"

/**
 * print_integer - Prints the contents of the number
 * @num: Array of numbers
 * Return: the number as string
 */

int print_integer(va_list args)
{
	char *num_s;
	int length;

/*	int_to_str(num_str, num);*/
	num_s = itac(va_arg(args, int), 10);
	length = put_string(num_s);
	return (length);
}
