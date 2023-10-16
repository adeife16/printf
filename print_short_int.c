#include "main.h"

/**
 * print_short_int - prints a short integer
 * @args: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed.
 */
int print_short_int(va_list args, char *buf, unsigned int ibuf)
{
    short int input;
    unsigned short int positive_input, temp, i, div;
    int is_negative;

    input = va_arg(args, int);
    is_negative = 0;

    if (input < 0)
    {
        positive_input = (unsigned short int)(input * -1);
        ibuf = handl_buf(buf, '-', ibuf);
        is_negative = 1;
    }
    else
    {
        positive_input = (unsigned short int)input;
    }

    temp = positive_input;
    div = 1;

    while (temp > 9)
    {
        div *= 10;
        temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        ibuf = handl_buf(buf, ((positive_input / div) % 10) + '0', ibuf);
    }

    return i + is_negative;
}