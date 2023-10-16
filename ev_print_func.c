#include "main.h"

/**
 * evaluate_print_function - returns the number of characters in the identifier.
 * @specifier: argument identifier
 * @index: index of the identifier.
 * Return: number of characters in the identifier.
 */
int evaluate_print_function(const char *specifier, int index)
{
    print_t print_functions[] = {
        {"c", print_character}, {"s", print_string}, {"i", print_integer},
        {"d", print_integer}, {"b", print_binary}, {"u", print_unsigned},
        {"o", print_octal}, {"x", print_hexadecimal}, {"X", print_uppercase_hex},
        {"S", print_string}, {"p", print_pointer}, {"li", print_long_integer},
        {"ld", print_long_integer}, {"lu", print_long_unsigned}, {"lo", print_long_octal},
        {"lx", print_long_hexadecimal}, {"lX", print_uppercase_long_hex},
        {"hi", print_short_integer}, {"hd", print_short_integer}, {"hu", print_short_unsigned},
        {"ho", print_short_octal}, {"hx", print_short_hexadecimal}, {"hX", print_uppercase_short_hex},
        {"#o", print_octal}, {"#x", print_hexadecimal}, {"#X", print_uppercase_hex},
        {"#i", print_integer}, {"#d", print_integer}, {"#u", print_unsigned},
        {"+i", print_integer}, {"+d", print_integer}, {"+u", print_unsigned},
        {"+o", print_octal}, {"+x", print_hexadecimal}, {"+X", print_uppercase_hex},
        {" i", print_integer}, {" d", print_integer}, {" u", print_unsigned},
        {" o", print_octal}, {" x", print_hexadecimal}, {" X", print_uppercase_hex},
        {"R", print_rot13}, {"r", print_reverse}, {"%", print_percentage},
        {"l", print_percentage}, {"h", print_percentage}, {" +i", print_integer},
        {" +d", print_integer}, {"+ i", print_integer}, {"+ d", print_integer},
        {" %", print_percentage},
        {NULL, NULL}
    };

    int i = 0, x = 0, first_index;

    first_index = index;

    while (print_functions[i].type_arg)
    {
        if (specifier[index] == print_functions[i].type_arg[x])
        {
            if (print_functions[i].type_arg[x + 1] != '\0')
                index++, x++;
            else
                break;
        }
        else
        {
            x = 0;
            i++;
            index = first_index;
        }
    }

    return x;
}