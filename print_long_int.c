#include "main.h"

/**
 * print_long_integer - prints a long integer
 * @arguments: input long integer
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_long_integer(va_list arguments, char *buf, unsigned int ibuf)
{
    long int long_input;
    unsigned long int unsigned_long_input, int_temp, i, div, is_negative;

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

    return i + is_negative;
}