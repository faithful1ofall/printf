#include "main.h"
/**
 * flag_handler1 - Prints an argument based on its type
 * @typ: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @lim: lim array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: 1 or 2;
 */
int flag_handler1(const char *typ, int *ind, va_list list, char lim[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	typ_t typ_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; typ_types[i].typ != '\0'; i++)
		if (typ[*ind] == typ_types[i].typ)
			return (typ_types[i].fa(list, lim, flags, width, precision, size));

	if (typ_types[i].typ == '\0')
	{
		if (typ[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (typ[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (typ[*ind] != ' ' && typ[*ind] != '%')
				--(*ind);
			if (typ[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &typ[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
