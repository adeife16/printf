#include "main.h"

/**
 * print_unsigned_int - prints an unsigned int
 * @args: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_unsigned_int(va_list args, char *buf, unsigned int ibuf)
{
    unsigned int int_value, int_temp, i, div;

    int_value = va_arg(args, unsigned int);
    int_temp = int_value;
    div = 1;

    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuf = handl_buf(buf, ((int_value / div) % 10) + '0', ibuf);
    }

    return i;
}
