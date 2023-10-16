#include "main.h"

/**
 * fill_long_octal_array - converts a binary array to a long octal number
 *
 * @binary_array: array where binary data is stored
 * @octal_string: array where the octal string will be stored
 *
 * Return: the octal string.
 */
char *fill_long_octal_array(char *binary_array, char *octal_string)
{
    int operation, i, j, octal_index, limit;

    octal_string[22] = '\0';

    for (i = 63, octal_index = 21; i >= 0; i--, octal_index--)
    {
        if (i > 0)
        {
            limit = 4;
        }
        else
        {
            limit = 1;
        }

        for (operation = 0, j = 1; j <= limit; j *= 2, i--)
        {
            operation = ((binary_array[i] - '0') * j) + operation;
        }
        i++;

        octal_string[octal_index] = operation + '0'; // Convert to ASCII
    }

    return octal_string;
}
