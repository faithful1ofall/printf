#include <unistd.h>

/**
 * print_char - Prints the contents of the buffer if it exist
 * @c: a single character or integer
 * Return: a single character 
 */

int print_char(char c) {
    return write(1, &c, 1);
}

/**
 * print_string - Prints a string of characters 
 * @str: Array of chars
 * Return: the characters
 */

int print_string(char *str) {
    int chars_printed = 0;
    while (*str != '\0') {
        chars_printed += print_char(str);
        str++;
    }
    return chars_printed;
}