#include "main.h"

/**
 * print_short_hex - prints a short decimal in hexadecimal
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_short_hex(va_list args, char *buf, unsigned int ibuf)
{
    short int input;
    int i, isnegative, count, first_digit;
    char *hexadecimal, *binary;

    input = va_arg(args, int);
    isnegative = 0;

    if (input == 0)
    {
        ibuf = handl_buf(buf, '0', ibuf);
        return 1;
    }

    if (input < 0)
    {
        input = (input * -1) - 1;
        isnegative = 1;
    }

    binary = malloc(sizeof(char) * (16 + 1));
    binary = fill_binary_array(binary, input, isnegative, 16);
    hexadecimal = malloc(sizeof(char) * (4 + 1));
    hexadecimal = fill_hex_array(binary, hexadecimal, 1, 4);

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
