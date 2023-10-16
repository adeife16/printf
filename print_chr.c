#include "main.h"
#include <stdio.h>

/**
 * print_char - writes the character c to the standard output
 * @arguments: input character
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 *
 * Return: On success, returns 1.
 */
int print_char(va_list arguments, char *buf, unsigned int ibuf)
{
    char character;

    character = va_arg(arguments, int);
    handle_buffer(buf, character, ibuf);

    return 1;
}