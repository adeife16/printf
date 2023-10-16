#include "main.h"

/**
 * print_string - writes a string to stdout
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_string(va_list args, char *buf, unsigned int ibuf)
{
    char *str;
    unsigned int i;
    char null_string[] = "(null)";

    str = va_arg(args, char *);

    if (str == NULL)
    {
        for (i = 0; null_string[i]; i++)
            ibuf = handl_buf(buf, null_string[i], ibuf);

        return 6;
    }

    for (i = 0; str[i]; i++)
        ibuf = handl_buf(buf, str[i], ibuf);

    return i;
}