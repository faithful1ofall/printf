/**
 * print_binary - Print a number in base 2
 * @list: Number to print in base 2
 * Return: Length of the numbers in binary
 **/
int print_binary(va_list args)
{
	char *fstr;
	int s;

	fstr = itac(va_arg(args, unsigned int), 2);

	s = print(fstr);

	return (s);
}
