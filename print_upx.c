#include "main.h"

/**
 * print_hex - prints a decimal in hexadecimal
 * @args: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_hex(va_list args, char *buf, unsigned int ibuf)
{
    int int_value, i, is_negative, count, first_digit;
    char *hexadecimal, *binary;

    int_value = va_arg(args, int);
    is_negative = 0;

    if (int_value == 0)
    {
        ibuf = handl_buf(buf, '0', ibuf);
        return 1;
    }

    if (int_value < 0)
    {
        int_value = (int_value * -1) - 1;
        is_negative = 1;
    }

    binary = malloc(sizeof(char) * (32 + 1));
    binary = fill_binary_array(binary, int_value, is_negative, 32);
    hexadecimal = malloc(sizeof(char) * (8 + 1));
    hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);

    for (first_digit = i = count = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] != '0' && first_digit == 0)
            first_digit = 1;

        if (first_digit)
        {
            ibuf = handl_buf(buf, hexadecimal[i], ibuf);
            count++;
        }
    }

    free(binary);
    free(hexadecimal);
    return count;
}
