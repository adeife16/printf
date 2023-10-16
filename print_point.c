#include "main.h"

/**
 * print_pointer - prints a pointer address in hexadecimal
 * @args: va_list containing the pointer address
 * @buffer: buffer to store the formatted string
 * @index: current index in the buffer
 *
 * Return: Number of characters printed
 */
int print_pointer(va_list args, char *buffer, unsigned int index)
{
    unsigned long int pointer_address;
    char *hexadecimal;
    int i, count, first_digit;

    pointer_address = va_arg(args, unsigned long int);

    if (pointer_address == 0)
    {
        index = handle_buffer(buffer, '0', index);
        index = handle_buffer(buffer, 'x', index);
        return (2);
    }

    index = handle_buffer(buffer, '0', index);
    index = handle_buffer(buffer, 'x', index);

    hexadecimal = malloc(sizeof(char) * (16 + 1));
    hexadecimal = fill_hex_array_for_pointer(pointer_address, hexadecimal, 16);

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
