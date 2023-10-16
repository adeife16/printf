#include "main.h"

/**
 * print_integer - prints an integer
 * @arguments: input integer
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_integer(va_list arguments, char *buf, unsigned int ibuf)
{
    int input_integer;
    unsigned int absolute_value, temp, i, divisor, is_negative;

    input_integer = va_arg(arguments, int);
    is_negative = 0;

    if (input_integer < 0)
    {
        absolute_value = (unsigned int)(input_integer * -1);
        ibuf = handle_buffer(buf, '-', ibuf);
        is_negative = 1;
    }
    else
    {
        absolute_value = (unsigned int)input_integer;
    }

    temp = absolute_value;
    divisor = 1;

    while (temp > 9)
    {
        divisor *= 10;
        temp /= 10;
    }

    for (i = 0; divisor > 0; divisor /= 10, i++)
    {
        ibuf = handle_buffer(buf, ((absolute_value / divisor) % 10) + '0', ibuf);
    }

    return i + is_negative;
}