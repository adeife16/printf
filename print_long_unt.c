#include "main.h"

/**
 * print_long_unsigned_int - prints a long unsigned integer
 * @arguments: number to print
 * @buf: buffer pointer
 * @ibuf: index for the buffer pointer
 *
 * Return: number of characters printed.
 */
int print_long_unsigned_int(va_list arguments, char *buf, unsigned int ibuf)
{
    unsigned long int unsigned_long_input, int_temp, i, div;

    unsigned_long_input = va_arg(arguments, unsigned long int);
    int_temp = unsigned_long_input;
    div = 1;

    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuf = handle_buffer(buf, ((unsigned_long_input / div) % 10) + '0', ibuf);
    }

    return i;
}