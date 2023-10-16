/**
 * print_r - Print a string in reverse
 * @args: List of arguments
 * Return: Length of the string
 **/
int print_r(va_list args)
{
	int i, s;
	const char *fstr;

	str = va_arg(args, const char *);

	s = _strlen(fstr);
	i = s - 1;

	while (i >= 0)
	{
		put_char(str[i]);
		i--;
	}
	return (s);
}
