#include "main.h"

/**
 * print_integer - Prints the contents of the number
 * @args: A list of arguments
 * @flags: the flag operators
 * @width: the width
 * @precision: the precision
 * @size: the size
 * @num_s: character array
 * Return: the number as string
 */

int print_integer(va_list args, int flags, int width,
int precision, int size, char num_s[])
{
	int i = 1022, is_negative = 0;
	long int nf = va_arg(args, long int);
	unsigned long int fnum;

	nf = conv_size_num(nf, size);

	if (nf == 0)
		num_s[i--] = '0';

	num_s[1023] = '\0';
	fnum = (unsigned long int)nf;

	if (nf < 0)
	{
		fnum = (unsigned long int)((-1) * nf);
		is_negative = 1;
	}

	while (fnum > 0)
	{
		num_s[i--] = (fnum % 10) + '0';
		fnum /= 10;
	}

	i++;

	return  (write_numb(is_negative, i, num_s, flags, width, precision));
}
