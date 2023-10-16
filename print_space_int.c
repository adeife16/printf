#include "main.h"

/**
 * print_signed_int_with_space - prints an integer beginning with a space
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_signed_int_with_space(va_list args, char *buf, unsigned int ibuf)
{
    int input;
    unsigned int absolute_value, temp, i, div;

    input = va_arg(args, int);

    if (input < 0)
    {
        absolute_value = input * -1;
        ibuf = handl_buf(buf, '-', ibuf);
    }
    else
    {
        absolute_value = input;
        ibuf = handl_buf(buf, ' ', ibuf);
    }

    temp = absolute_value;
    div = 1;

    while (temp > 9)
    {
        div *= 10;
        temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuf = handl_buf(buf, ((absolute_value / div) % 10) + '0', ibuf);
    }

    return i + 1;
}
