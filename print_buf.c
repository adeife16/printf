#include "main.h"

/**
 * print_buffer - prints a buffer to the standard output
 * @buffer: buffer pointer
 * @buffer_size: number of bytes to print
 *
 * Return: number of bytes printed.
 */
int print_buffer(char *buffer, unsigned int buffer_size)
{
    return (write(1, buffer, buffer_size));
}
