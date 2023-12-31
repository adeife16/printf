#include "main.h"

/**
 * _printf - a custom implementation of printf
 * @format: input string.
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, char_count = 0, buffer_index = 0;
	va_list args;
	int (*print_function)(va_list, char *, unsigned int);
	char *output_buffer;

	va_start(args, format);
	output_buffer = malloc(sizeof(char) * 1024);

	if (!format || !output_buffer || (format[i] == '%' && !format[i + 1]))
	{
		return (-1);
	}

	if (!format[i])
	{
		return (0);
	}

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buffer(output_buffer, buffer_index);
				free(output_buffer);
				va_end(args);
				return (-1);
			}
			else
			{
				print_function = get_print_function(format, i + 1);

				if (print_function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
					{
						return (-1);
					}
					handle_buffer(output_buffer, format[i], buffer_index);
					char_count++;
					i--;
				}
				else
				{
					char_count += print_function(args, output_buffer, buffer_index);
					i += evaluate_print_function(format, i + 1);
				}
			}
			i++;
		}
		else
		{
			handle_buffer(output_buffer, format[i], buffer_index);
			char_count++;
		}

		for (buffer_index = char_count; buffer_index > 1024; buffer_index -= 1024)
		{
			/* Adjust the buffer index. */
		}
	}

	print_buffer(output_buffer, buffer_index);
	free(output_buffer);
	va_end(args);

	return (char_count);
}
