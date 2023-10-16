#include "main.h"

/**
 * print_positive_hexadecimal - prints a hexadecimal number with a plus symbol
 * @args: input number
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of characters printed
 */
int print_positive_hexadecimal(va_list args, char *buffer, unsigned int index)
{
    unsigned int hex_input, temp, div;
    int i = 0;

    hex_input = va_arg(args, unsigned int);

    if (hex_input == 0)
    {
        buffer[index] = '0';
        index++;
        return 1;
    }

    temp = hex_input;
    div = 1;

    while (temp > 15)
    {
        div *= 16;
        temp /= 16;
    }

    buffer[index] = '+';
    index++;

    for (i = 0; div > 0; div /= 16, i++)
    {
        int remainder = (hex_input / div) % 16;
        if (remainder < 10)
            buffer[index] = remainder + '0';
        else
            buffer[index] = (remainder - 10) + 'a';  // for 'a' to 'f'
        index++;
    }

    return i + 1;
}
