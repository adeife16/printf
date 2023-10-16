#include "main.h"

/**
 * print_short_unsigned_int - prints a short unsigned integer
 * @args: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed.
 */
int print_short_unsigned_int(va_list args, char *buf, unsigned int ibuf)
{
    unsigned short int input;
    unsigned short int temp, i, div;

    input = va_arg(args, unsigned int);

    temp = input;
    div = 1;

    while (temp > 9)
    {
        div *= 10;
        temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuf = handl_buf(buf, ((input / div) % 10) + '0', ibuf);
    }

    return i;
}