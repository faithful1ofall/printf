/**
 * print_integer - Prints the contents of the number
 * @num: Array of numbers
 * Return: the number as string
 */

int print_integer(int num)
{
	char num_str[20];
	int length;

	int_to_str(num_str, num);
	length = num_length(num);
	return (write(1, num_str, length));
}
