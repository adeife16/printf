#include "main.h"

/**
 * print_percent - writes the character '%' to the buffer
 * @args: unused argument list
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: 1 (the number of characters printed)
 */
int print_percent(va_list args __attribute__((unused)), char *buf, unsigned int ibuf)
{
    handl_buf(buf, '%', ibuf);

    return (1);
}