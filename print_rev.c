#include "main.h"

/**
 * print_reverse - writes the string in reverse order
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_reverse(va_list args, char *buf, unsigned int ibuf)
{
    char *str;
    unsigned int i;
    int j = 0;
    char nil[] = "(nil)";

    str = va_arg(args, char *);
    if (str == NULL)
    {
        for (i = 0; nil[i]; i++)
            ibuf = handl_buf(buf, nil[i], ibuf);
        return 5;
    }
    for (i = 0; str[i]; i++)
        ;

    j = i - 1;

    for (; j >= 0; j--)
    {
        ibuf = handl_buf(buf, str[j], ibuf);
    }
    return i;
}
