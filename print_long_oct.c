#include "main.h"

/**
 * print_long_octal - prints a long decimal number in octal
 * @arguments: input long number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_long_octal(va_list arguments, char *buf, unsigned int ibuf)
{
    long int long_input;
    unsigned long int unsigned_long_input, int_temp, i, div, is_negative;
    char *octal, *binary;

    long_input = va_arg(arguments, long int);
    is_negative = 0;

    if (long_input < 0)
    {
        unsigned_long_input = (unsigned long int)(long_input * -1);
        ibuf = handle_buffer(buf, '-', ibuf);
        is_negative = 1;
    }
    else
    {
        unsigned_long_input = (unsigned long int)long_input;
    }

    if (unsigned_long_input == 0)
    {
        ibuf = handle_buffer(buf, '0', ibuf);
        return 1;
    }

    binary = malloc(sizeof(char) * (64 + 1));
    binary = fill_binary_array(binary, unsigned_long_input, 0, 64);
    octal = malloc(sizeof(char) * (22 + 1));
    octal = fill_long_octal_array(binary, octal);

    for (int first_digit = i = 0; octal[i]; i++)
    {
        if (octal[i] != '0' && first_digit == 0)
            first_digit = 1;

        if (first_digit)
        {
            ibuf = handle_buffer(buf, octal[i], ibuf);
            i++;
        }
    }

    free(binary);
    free(octal);
    return i;
}