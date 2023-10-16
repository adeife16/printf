#include "main.h"

/**
 * print_space_padded_integer - prints an integer with space padding
 * @args: input number
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of characters printed
 */
int print_space_padded_integer(va_list args, char *buffer, unsigned int index)
{
    int int_input;
    unsigned int int_in, int_temp, i, div;

    int_input = va_arg(args, int);

    int_in = (int_input < 0) ? -int_input : int_input;

    if (int_input < 0)
    {
        buffer[index] = '-';
        index++;
    }
    else
    {
        buffer[index] = ' ';
        index++;
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
        buffer[index] = ((int_in / div) % 10) + '0';
        index++;
    }

    return i + 1;  // +1 to account for '-' or ' '
}

