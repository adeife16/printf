#include "main.h"

/**
 * print_positive_uppercase_hex - prints a positive decimal in uppercase hexadecimal
 * @args: input number
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of characters printed
 */
int print_positive_uppercase_hex(va_list args, char *buffer, unsigned int index)
{
    int int_input;
    unsigned int int_in, int_temp, i, div;

    int_input = va_arg(args, int);

    int_in = (int_input < 0) ? -int_input : int_input;

    buffer[index] = '+';
    index++;
    buffer[index] = '0';
    index++;
    buffer[index] = 'X';
    index++;

    int_temp = int_in;
    div = 1;

    while (int_temp > 15)
    {
        div *= 16;
        int_temp /= 16;
    }

    for (i = 0; div > 0; div /= 16, i++)
    {
        int remainder = (int_in / div) % 16;
        buffer[index] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
        index++;
    }

    return i + 3;  // +3 to account for '+', '0', and 'X'
}

