#include "main.h"

/**
 * print_positive_integer - print an integer with a plus symbol
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_positive_integer(va_list arguments, char *buf, unsigned int ibuf)
{
    int int_input;
    unsigned int int_in, int_temp, i, div;

    int_input = va_arg(arguments, int);

    if (int_input < 0)
    {
        int_in = int_input * -1;
        ibuf = handle_buffer(buf, '-', ibuf);
    }
    else
    {
        int_in = int_input;
        ibuf = handle_buffer(buf, '+', ibuf);
    }

    int_temp = int_in;
    div = 1;

    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuf = handle_buffer(buf, ((int_in / div) % 10) + '0', ibuf);
    }

    return i + 1;
}
