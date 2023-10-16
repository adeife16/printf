#include "main.h"

/**
 * print_unprintable_str - prints a string and values of
 * non-printed chars
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_unprintable_str(va_list args, char *buf, unsigned int ibuf)
{
    unsigned char *str;
    char *hexadecimal, *binary;
    unsigned int i, extra_chars, unprintable_char;

    str = va_arg(args, unsigned char *);
    binary = malloc(sizeof(char) * (32 + 1));
    hexadecimal = malloc(sizeof(char) * (8 + 1));

    for (extra_chars = i = 0; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            ibuf = handl_buf(buf, '\\', ibuf);
            ibuf = handl_buf(buf, 'x', ibuf);
            unprintable_char = str[i];
            binary = fill_binary_array(binary, unprintable_char, 0, 32);
            hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);
            ibuf = handl_buf(buf, hexadecimal[6], ibuf);
            ibuf = handl_buf(buf, hexadecimal[7], ibuf);
            extra_chars += 3;
        }
        else
        {
            ibuf = handl_buf(buf, str[i], ibuf);
        }
    }

    free(binary);
    free(hexadecimal);
    return (i + extra_chars);
}