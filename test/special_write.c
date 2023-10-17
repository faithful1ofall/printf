#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * write_c - Prints a string
 * @c: char types.
 * @lim: lim array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_c(char c, char lim[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at lim's right */
	int i = 0;
	char padd = ' ';

	NO(precision);
	NO(size);

	if (flags & C_ZERO)
		padd = '0';

	lim[i++] = c;
	lim[i] = '\0';

	if (width > 1)
	{
		lim[1024 - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			lim[1024 - i - 2] = padd;

		if (flags & C_MINUS)
			return (write(1, &lim[0], 1) +
					write(1, &lim[1024 - i - 1], width - 1));
		else
			return (write(1, &lim[1024 - i - 1], width - 1) +
					write(1, &lim[0], 1));
	}

	return (write(1, &lim[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_fnumb - Prints a string
 * @negative: Lista of arguments
 * @ind: char types.
 * @lim: lim array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_fnumb(int negative, int ind, char lim[],
	int flags, int width, int precision, int size)
{
	int length = 1024 - ind - 1;
	char padd = ' ', extra_ch = 0;

	NO(size);

	if ((flags & C_ZERO) && !(flags & C_MINUS))
		padd = '0';
	if (negative)
		extra_ch = '-';
	else if (flags & C_PLUS)
		extra_ch = '+';
	else if (flags & C_SPACE)
		extra_ch = ' ';

	return (write_fnum(ind, lim, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_fnum - Write a number using a bufffer
 * @ind: Index at which the number starts on the lim
 * @lim: lim
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_fnum(int ind, char lim[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == 1024 - 2 && lim[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == 1024 - 2 && lim[ind] == '0')
		lim[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		lim[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			lim[i] = padd;
		lim[i] = '\0';
		if (flags & C_MINUS && padd == ' ')/* Asign extra char to left of lim */
		{
			if (extra_c)
				lim[--ind] = extra_c;
			return (write(1, &lim[ind], length) + write(1, &lim[1], i - 1));
		}
		else if (!(flags & C_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				lim[--ind] = extra_c;
			return (write(1, &lim[1], i - 1) + write(1, &lim[ind], length));
		}
		else if (!(flags & C_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				lim[--padd_start] = extra_c;
			return (write(1, &lim[padd_start], i - padd_start) +
				write(1, &lim[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		lim[--ind] = extra_c;
	return (write(1, &lim[ind], length));
}

/**
 * write_u - Writes an unsigned number
 * @negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the lim
 * @lim: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_u(int negative, int ind,
	char lim[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = 1024 - ind - 1, i = 0;
	char padd = ' ';

	NO(negative);
	NO(size);

	if (precision == 0 && ind == 1024 - 2 && lim[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		lim[--ind] = '0';
		length++;
	}

	if ((flags & C_ZERO) && !(flags & C_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			lim[i] = padd;

		lim[i] = '\0';

		if (flags & C_MINUS) /* Asign extra char to left of lim [lim>padd]*/
		{
			return (write(1, &lim[ind], length) + write(1, &lim[0], i));
		}
		else /* Asign extra char to left of padding [padd>lim]*/
		{
			return (write(1, &lim[0], i) + write(1, &lim[ind], length));
		}
	}

	return (write(1, &lim[ind], length));
}

/**
 * write_p - Write a memory address
 * @lim: Arrays of chars
 * @ind: Index at which the number starts in the lim
 * @length: Length of number
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_p(char lim[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			lim[i] = padd;
		lim[i] = '\0';
		if (flags & C_MINUS && padd == ' ')/* Asign extra char to left of lim */
		{
			lim[--ind] = 'x';
			lim[--ind] = '0';
			if (extra_c)
				lim[--ind] = extra_c;
			return (write(1, &lim[ind], length) + write(1, &lim[3], i - 3));
		}
		else if (!(flags & C_MINUS) && padd == ' ')/* extra char to left of lim */
		{
			lim[--ind] = 'x';
			lim[--ind] = '0';
			if (extra_c)
				lim[--ind] = extra_c;
			return (write(1, &lim[3], i - 3) + write(1, &lim[ind], length));
		}
		else if (!(flags & C_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				lim[--padd_start] = extra_c;
			lim[1] = '0';
			lim[2] = 'x';
			return (write(1, &lim[padd_start], i - padd_start) +
				write(1, &lim[ind], length - (1 - padd_start) - 2));
		}
	}
	lim[--ind] = 'x';
	lim[--ind] = '0';
	if (extra_c)
		lim[--ind] = extra_c;
	return (write(1, &lim[ind], 1024 - ind - 1));
}
