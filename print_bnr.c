#include "main.h"

/**
 * print_binary - prints a decimal number in binary
 * @arguments: input integer
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_binary(va_list arguments, char *buf, unsigned int ibuf)
{
    int integer_input, count, i, first_one, is_negative;
    char *binary;

    integer_input = va_arg(arguments, int);
    is_negative = 0;

    if (integer_input == 0)
    {
        ibuf = handle_buffer(buf, '0', ibuf);
        return 1;
    }

    if (integer_input < 0)
    {
        integer_input = (integer_input * -1) - 1;
        is_negative = 1;
    }

    binary = malloc(sizeof(char) * (32 + 1));
    binary = fill_binary_array(binary, integer_input, is_negative, 32);

    first_one = 0;

    for (count = i = 0; binary[i]; i++)
    {
        if (first_one == 0 && binary[i] == '1')
            first_one = 1;

        if (first_one == 1)
        {
            ibuf = handle_buffer(buf, binary[i], ibuf);
            count++;
        }
    }

    free(binary);
    return count;
}
