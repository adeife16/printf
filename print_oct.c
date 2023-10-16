#include "main.h"

/**
 * print_octal - prints a decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_octal(va_list arguments, char *buf, unsigned int ibuf)
{
    int int_input, i, isnegative, count, first_digit;
    char *octal, *binary;

    int_input = va_arg(arguments, int);
    isnegative = 0;

    if (int_input == 0)
    {
        ibuf = handle_buffer(buf, '0', ibuf);
        return 1;
    }

    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }

    binary = malloc(sizeof(char) * (32 + 1));
    binary = fill_binary_array(binary, int_input, isnegative, 32);

    octal = malloc(sizeof(char) * (11 + 1));
    octal = fill_octal_array(binary, octal);

    for (first_digit = i = count = 0; octal[i]; i++)
    {
        if (octal[i] != '0' && first_digit == 0)
        {
            first_digit = 1;
        }
        if (first_digit)
        {
            ibuf = handle_buffer(buf, octal[i], ibuf);
            count++;
        }
    }

    free(binary);
    free(octal);

    return count;
}