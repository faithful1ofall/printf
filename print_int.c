#include "main.h"

/**
 * print_integer - Prints the contents of the number
 * @args: A list of arguments
 * Return: the number as string
 */

int print_integer(va_list args)
{
	char *num_s;
	int length;

	num_s = itac(va_arg(args, int), 10);
	length = put_string((num_s != NULL) ? num_s : "NULL");
	return (length);
}
