#include <unistd.h>

int print_char(int c) {
    return write(1, &c, 1);
}

int print_string(char *str) {
    int chars_printed = 0;
    while (*str != '\0') {
        chars_printed += print_char(str);
        str++;
    }
    return chars_printed;
}
