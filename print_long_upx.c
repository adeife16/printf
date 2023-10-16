#include "main.h"

/**
 * print_long_upper_hex - prints a long decimal in hexadecimal
 * @arguments: The number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_long_upper_hex(va_list arguments, char *buf, unsigned int ibuf)
{
    long int long_input, i, isnegative, count, first_digit;
    char *hexadecimal, *binary;

    long_input = va_arg(arguments, long int);
    isnegative = 0;

    if (long_input == 0)
    {
        ibuf = handle_buffer(buf, '0', ibuf);
        return 1;
    }

    if (long_input < 0)
    {
        long_input = (long_input * -1) - 1;
        isnegative = 1;
    }

    binary = malloc(sizeof(char) * (64 + 1));
    binary = fill_binary_array(binary, long_input, isnegative, 64);
    hexadecimal = malloc(sizeof(char) * (16 + 1));
    hexadecimal = fill_hex_array(binary, hexadecimal, 1, 16);

    for (first_digit = i = count = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] != '0' && first_digit == 0)
        {
            first_digit = 1;
        }
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