#include "main.h"

/**
 * print_rot13 - writes the string in ROT13 encoding
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of characters printed
 */
int print_rot13(va_list args, char *buf, unsigned int ibuf)
{
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    char *str;
    unsigned int i, j, k;
    char nil[] = "(null)";

    str = va_arg(args, char *);
    if (str == NULL)
    {
        for (i = 0; nil[i]; i++)
            ibuf = handl_buf(buf, nil[i], ibuf);
        return 6;
    }
    for (i = 0; str[i]; i++)
    {
        for (k = j = 0; alphabet[j]; j++)
        {
            if (str[i] == alphabet[j])
            {
                k = 1;
                ibuf = handl_buf(buf, rot13[j], ibuf);
                break;
            }
        }
        if (k == 0)
            ibuf = handl_buf(buf, str[i], ibuf);
    }
    return i;
}
