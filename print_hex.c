#include "main.h"

/**
 * print_hexadecimal - prints a decimal number in hexadecimal
 * @arguments: input integer
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_hexadecimal(va_list arguments, char *buf, unsigned int ibuf)
{
    int integer_input, i, isnegative, count, first_digit;
    char *hexadecimal, *binary;

    integer_input = va_arg(arguments, int);
    isnegative = 0;

    if (integer_input == 0)
    {
        ibuf = handle_buffer(buf, '0', ibuf);
        return 1;
    }

    if (integer_input < 0)
    {
        integer_input = (integer_input * -1) - 1;
        isnegative = 1;
    }

    binary = malloc(sizeof(char) * (32 + 1));
    binary = fill_binary_array(binary, integer_input, isnegative, 32);
    hexadecimal = malloc(sizeof(char) * (8 + 1));
    hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);

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