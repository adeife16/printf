#include "main.h"

/**
 * print_positive_octal - prints an octal number with a plus symbol
 * @args: input number
 * @buffer: buffer pointer
 * @index: index for buffer pointer
 * Return: number of characters printed
 */
int print_positive_octal(va_list args, char *buffer, unsigned int index)
{
    unsigned int octal_input, temp, div;
    int i = 0;

    octal_input = va_arg(args, unsigned int);

    if (octal_input == 0)
    {
        buffer[index] = '0';
        index++;
        return 1;
    }

    temp = octal_input;
    div = 1;

    while (temp > 7)
    {
        div *= 8;
        temp /= 8;
    }

    buffer[index] = '+';
    index++;
    
    for (i = 0; div > 0; div /= 8, i++)
    {
        buffer[index] = ((octal_input / div) % 8) + '0';
        index++;
    }

    return i + 1;
}
