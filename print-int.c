#include "main.h"

/**
 * print_integer - Prints the contents of the number
 * @num: Array of numbers
 * Return: the number as string
 */

int print_integer(int num)
{
	char *num_s;
	int length;

/*	int_to_str(num_str, num);*/
	num_s = itac(num, 10);
	length = put_string(num_s);
	return (length);
}
