#include <unistd.h> // For write
#include <stdlib.h> // For malloc and free
#include <stdarg.h> // For va_start, va_end, va_arg

// Function to calculate the length of an integer
int num_length(int num) {
	int length = 1;
	if (num < 0) {
		length++;
		num = -num;
	}
	while (num >= 10) {
		length++;
		num /= 10;
	}
	return length;
}

// Function to convert an integer to a string
void int_to_str(char *str, int num) {
	int i = 0;
	if (num < 0) {
		str[i++] = '-';
		num = -num;
	}
	int length = num_length(num);
	for (int j = length - 1; j >= 0; j--) {
		str[i + j] = '0' + (num % 10);
		num /= 10;
	}
	str[i + length] = '\0';
}

int _printf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	int chars_printed = 0;

	while (*format != '\0') {
		if (*format != '%') {
			write(STDOUT_FILENO, format, 1);
			chars_printed++;
		} else {
			format++; // Move past the '%'
			switch (*format) {
				case 'c': {
						  int c = va_arg(args, int);
						  write(STDOUT_FILENO, &c, 1);
						  chars_printed++;
						  break;
					  }
				case 's': {
						  char *str = va_arg(args, char *);
						  while (*str != '\0') {
							  write(STDOUT_FILENO, str, 1);
							  str++;
							  chars_printed++;
						  }
						  break;
					  }
				case '%': {
						  write(STDOUT_FILENO, "%", 1);
						  chars_printed++;
						  break;
					  }
				case 'd':
				case 'i': {
						  int num = va_arg(args, int);
						  char num_str[12]; // Maximum number of digits for a 32-bit int
						  int_to_str(num_str, num);
						  int length = num_length(num);
						  write(STDOUT_FILENO, num_str, length);
						  chars_printed += length;
						  break;
					  }
				default:
					  // Unsupported format specifier
					  return -1;
			}
		}
		format++;
	}

	va_end(args);
	return chars_printed;
}
