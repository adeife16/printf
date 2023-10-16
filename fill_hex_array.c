#include "main.h"

/**
 * fill_hexadecimal_array - converts a binary array to a hexadecimal string
 * @binary_array: array where binary data is stored
 * @hexadecimal_string: array where the hexadecimal string will be stored
 * @is_uppercase: determines if the hexadecimal string is in uppercase or lowercase
 * @hex_limit: size of the hexadecimal string
 *
 * Return: the hexadecimal string.
 */
char *fill_hexadecimal_array(char *binary_array, char *hexadecimal_string, int is_uppercase, int hex_limit)
{
    int operation, i, j, to_letter;

    hexadecimal_string[hex_limit] = '\0';

    if (is_uppercase)
    {
        to_letter = 55; // ASCII value of 'A' - 10
    }
    else
    {
        to_letter = 87; // ASCII value of 'a' - 10
    }

    for (i = (hex_limit * 4) - 1; i >= 0; i--)
    {
        for (operation = 0, j = 1; j <= 8; j *= 2, i--)
        {
            operation = ((binary_array[i] - '0') * j) + operation;
        }
        i++;

        if (operation < 10)
        {
            hexadecimal_string[i / 4] = operation + 48; // Convert to ASCII
        }
        else
        {
            hexadecimal_string[i / 4] = operation + to_letter; // Convert to ASCII
        }
    }

    return hexadecimal_string;
}