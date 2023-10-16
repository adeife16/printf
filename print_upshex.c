#include "main.h"

/**
 * print_uppercase_short_hex - prints a short integer in uppercase hexadecimal
 * @args: va_list containing the short integer
 * @buffer: buffer to store the formatted string
 * @index: current index in the buffer
 *
 * Return: Number of characters printed
 */
int print_uppercase_short_hex(va_list args, char *buffer, unsigned int index)
{
    short int short_value;
    char *hexadecimal;
    int i, count, first_digit;

    short_value = (short int)va_arg(args, int);

    if (short_value == 0)
    {
        index = handle_buffer(buffer, '0', index);
        index = handle_buffer(buffer, 'X', index);
        return (2);
    }

    index = handle_buffer(buffer, '0', index);
    index = handle_buffer(buffer, 'X', index);

    hexadecimal = malloc(sizeof(char) * (4 + 1));
    hexadecimal = fill_hexadecimal_array(hexadecimal, short_value, 1, 4);

    for (first_digit = i = count = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] != '0' && first_digit == 0)
            first_digit = 1;

        if (first_digit)
        {
            index = handle_buffer(buffer, hexadecimal[i], index);
            count++;
        }
    }

    free(hexadecimal);
    return (count + 2);
}
