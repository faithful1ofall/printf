#include <stdarg.h>
#include <unistd.h>

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


int print_integer(int num) {
    char num_str[1024];
    int_to_str(num_str, num);
    int length = num_length(num);
    return write(1, num_str, length);
}

int handle_format_specifier(char format, va_list args) {
    int chars_printed = 0;

    switch (format) {
        case 'c':
            chars_printed += print_char(va_arg(args, int));
            break;
        case 's':
            chars_printed += print_string(va_arg(args, char *));
            break;
        case '%':
            chars_printed += print_char('%');
            break;
        case 'd':
        case 'i':
            chars_printed += print_integer(va_arg(args, int));
            break;
        default:
            return -1;
    }

    return chars_printed;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_printed = 0;

    while (*format != '\0') {
        if (*format != '%') {
            chars_printed += print_char(*format);
        } else {
            format++;
            chars_printed += handle_format_specifier(*format, args);
        }
        format++;
    }

    va_end(args);
    return chars_printed;
}
