#include <stdarg.h>
#include <unistd.h>

// Function to print a character
int print_char(int c) {
    return write(1, &c, 1);
}

// Function to print a string
int print_string(char *str) {
    int chars_printed = 0;
    while (*str != '\0') {
        chars_printed += print_char(str);
        str++;
    }
    return chars_printed;
}

// Function to print an integer
int print_integer(int num) {
    char num_str[12];
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
