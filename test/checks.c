#include "main.h"

/**
 * check_flags - Calculates active flags
 * @fstr: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int check_flags(const char *fstr, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {C_MINUS, C_PLUS, C_ZERO, C_HASH, C_SPACE, 0};

	for (curr_i = *i + 1; fstr[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (fstr[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

#include "main.h"

/**
 * check_precision - Calculates the precision for printing
 * @fstr: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @fargs: list of arguments.
 *
 * Return: Precision.
 */
int check_precision(const char *fstr, int *i, va_list fargs)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (fstr[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; fstr[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(fstr[curr_i]))
		{
			precision *= 10;
			precision += fstr[curr_i] - '0';
		}
		else if (fstr[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(fargs, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

#include "main.h"

/**
 * check_size -Calculates the size to cast the argument
 * @fstr: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int check_size(const char *fstr, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (fstr[curr_i] == 'l')
		size = C_LONG;
	else if (fstr[curr_i] == 'h')
		size = C_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

#include "main.h"

/**
 * check_width - Calculates the width for printing
 * @fstr: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @fargs: list of arguments.
 *
 * Return: width.
 */
int check_width(const char *fstr, int *i, va_list fargs)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; fstr[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(fstr[curr_i]))
		{
			width *= 10;
			width += fstr[curr_i] - '0';
		}
		else if (fstr[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(fargs, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
