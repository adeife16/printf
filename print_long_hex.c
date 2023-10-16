#include "main.h"

/**
 * print_long_hexadecimal - prints a long decimal number in hexadecimal
 * @arguments: input long integer
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_long_hexadecimal(va_list arguments, char *buf, unsigned int ibuf)
{
    long int long_input, i, is_negative, count, first_digit;
    char *hexadecimal, *binary;

    long_input = va_arg(arguments, long int);
    is_negative = 0;

    if (long_input == 0)
    {
        ibuf = handle_buffer(buf, '0', ibuf);
        return 1;
    }

    if (long_input < 0)
    {
        long_input = (long_input * -1) - 1;
        is_negative = 1;
    }

    binary = malloc(sizeof(char) * (64 + 1));
    binary = fill_binary_array(binary, long_input, is_negative, 64);
    hexadecimal = malloc(sizeof(char) * (16 + 1));
    hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);

    for (first_digit = i = count = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] != '0' && first_digit == 0)
            first_digit = 1;

        if (first_digit)
        {
            ibuf = handle_buffer(buf, hexadecimal[i], ibuf);
            count++;
        }
    }

    free(binary);
    free(hexadecimal);
    return count;
}
