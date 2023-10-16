#include "main.h"

/**
 * print_positive_unsigned - prints an unsigned integer with a plus symbol
 * @args: input number
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of characters printed
 */
int print_positive_unsigned(va_list args, char *buffer, unsigned int index)
{
    unsigned int unsigned_input;
    unsigned int int_in, int_temp, i, div;

    unsigned_input = va_arg(args, unsigned int);

    int_in = unsigned_input;
    buffer[index] = '+';
    index++;

    int_temp = int_in;
    div = 1;

    while (int_temp > 9)
    {
        div *= 10;
        int_temp /= 10;
    }

    for (i = 0; div > 0; div /= 10, i++)
    {
        buffer[index] = ((int_in / div) % 10) + '0';
        index++;
    }

    return i + 1;
}
