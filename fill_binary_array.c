#include "main.h"

/**
 * fill_binary_array - converts a decimal number to a binary string
 * @binary_string: pointer to the binary string
 * @decimal_number: input decimal number
 * @is_negative: flag indicating if the input number is negative
 * @binary_limit: size of the binary string
 *
 * Return: the binary string representing the decimal number.
 */
char *fill_binary_array(char *binary_string, long int decimal_number, int is_negative, int binary_limit)
{
    int i;

    for (i = 0; i < binary_limit; i++)
    {
        binary_string[i] = '0';
    }
    binary_string[binary_limit] = '\0';

    for (i = binary_limit - 1; decimal_number > 1; i--)
    {
        if (decimal_number == 2)
        {
            binary_string[i] = '0';
        }
        else
        {
            binary_string[i] = (decimal_number % 2) + '0';
        }
        decimal_number /= 2;
    }

    if (decimal_number != 0)
    {
        binary_string[i] = '1';
    }

    if (is_negative)
    {
        for (i = 0; binary_string[i]; i++)
        {
            if (binary_string[i] == '0')
            {
                binary_string[i] = '1';
            }
            else
            {
                binary_string[i] = '0';
            }
        }
    }

    return binary_string;
}