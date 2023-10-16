#include "main.h"
#include <stdio.h>

/**
 * print_address - prints the address of an input variable
 * @arguments: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer
 *
 * Return: number of characters printed.
 */
int print_address(va_list arguments, char *buf, unsigned int ibuf)
{
    void *address;
    long int int_input;
    int i, count, first_digit, isnegative;
    char *hexadecimal, *binary;
    char nill[] = "(nil)";

    address = (va_arg(arguments, void *));
    if (address == NULL)
    {
        for (i = 0; nill[i]; i++)
            ibuf = handle_buffer(buf, nill[i], ibuf);
        return (5);
    }
    int_input = (intptr_t)address;
    isnegative = 0;
    if (int_input < 0)
    {
        int_input = (int_input * -1) - 1;
        isnegative = 1;
    }
    binary = malloc(sizeof(char) * (64 + 1));
    binary = fill_binary_array(binary, int_input, isnegative, 64);
    hexadecimal = malloc(sizeof(char) * (16 + 1));
    hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
    ibuf = handle_buffer(buf, '0', ibuf);
    ibuf = handle_buffer(buf, 'x', ibuf);
    for (first_digit = i = count = 0; hexadecimal[i]; i++)
    {
        if (hexadecimal[i] != '0' && first_digit == 0)
            first_digit = 1;
        if (first_digit)
        {
            ibuf = handle_buffer(buf, hexadecimal[i], ibuf);
            count++;
        }
    }
    free(binary);
    free(hexadecimal);
    return (count + 2);
}