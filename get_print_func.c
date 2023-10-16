#include "main.h"

/**
 * get_print_function - selects the correct function to perform the operation.
 * @specifier: argument identifier
 * @index: index for the argument identifier
 *
 * Return: pointer to a function.
 */
int (*get_print_function(const char *specifier, int index))(va_list, char *, unsigned int)
{
    print_t print_functions[] = {
        {"c", print_character}, {"s", print_string}, {"i", print_integer},
        {"d", print_integer}, {"b", print_binary}, {"u", print_unsigned},
        {"o", print_octal}, {"x", print_hexadecimal}, {"X", print_uppercase_hex},
        //{"S", print_string}, {"p", print_address}, {"li", print_long_integer},
        {"ld", print_long_integer}, {"lu", print_long_unsigned}, {"lo", print_long_octal},
        {"lx", print_long_hexadecimal}, {"lX", print_uppercase_long_hex},
        {"hi", print_short_integer}, {"hd", print_short_integer}, {"hu", print_short_unsigned},
        {"ho", print_short_octal}, {"hx", print_short_hexadecimal}, {"hX", print_uppercase_short_hex},
        {"#o", print_octal}, {"#x", print_hexadecimal}, {"#X", print_uppercase_hex},
        {"#i", print_integer}, {"#d", print_integer}, {"#u", print_unsigned},
        {"+i", print_positive_integer}, {"+d", print_positive_integer}, {"+u", print_positive_unsigned},
        {"+o", print_positive_octal}, {"+x", print_positive_hexadecimal}, {"+X", print_positive_uppercase_hex},
        {" i", print_space_padded_integer}, {" d", print_space_padded_integer}, {" u", print_unsigned},
        {" o", print_octal}, {" x", print_hexadecimal}, {" X", print_uppercase_hex},
        {"R", print_rot13}, {"r", print_reverse}, {"%", print_percentage},
        {"l", print_percentage}, {"h", print_percentage}, {" +i", print_positive_integer},
        {" +d", print_positive_integer}, {"+ i", print_positive_integer}, {"+ d", print_positive_integer},
        {" %", print_percentage},
        {NULL, NULL}
    };

    int i = 0, j = 0, first_index;

    first_index = index;
    while (print_functions[i].type_arg)
    {
        if (specifier[index] == print_functions[i].type_arg[j])
        {
            if (print_functions[i].type_arg[j + 1] != '\0')
            {
                index++, j++;
            }
            else
            {
                break;
            }
        }
        else
        {
            j = 0;
            i++;
            index = first_index;
        }
    }

    return (print_functions[i].f);
}
