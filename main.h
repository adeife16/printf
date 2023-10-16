#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct print
{
    char *type_arg;
    int (*print_func)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int print_percentage(va_list args, char *buffer, unsigned int index);
int print_character(va_list args, char *buffer, unsigned int index);
int print_string(va_list args, char *buffer, unsigned int index);
int print_integer(va_list args, char *buffer, unsigned int index);
int print_binary(va_list args, char *buffer, unsigned int index);
int print_unsigned(va_list args, char *buffer, unsigned int index);
int print_octal(va_list args, char *buffer, unsigned int index);
int print_hexadecimal(va_list args, char *buffer, unsigned int index);
int print_uppercase_hex(va_list args, char *buffer, unsigned int index);
int print_pointer(va_list args, char *buffer, unsigned int index);
int print_reverse(va_list args, char *buffer, unsigned int index);
int print_rot13(va_list args, char *buffer, unsigned int index);
int print_long_integer(va_list args, char *buffer, unsigned int index);
int print_long_unsigned(va_list args, char *buffer, unsigned int index);
int print_long_octal(va_list args, char *buffer, unsigned int index);
int print_long_hexadecimal(va_list args, char *buffer, unsigned int index);
int print_uppercase_long_hex(va_list args, char *buffer, unsigned int index);
int print_short_integer(va_list args, char *buffer, unsigned int index);
int print_short_unsigned(va_list args, char *buffer, unsigned int index);
int print_short_octal(va_list args, char *buffer, unsigned int index);
int print_short_hexadecimal(va_list args, char *buffer, unsigned int index);
int print_uppercase_short_hex(va_list args, char *buffer, unsigned int index);
int print_hh_integer(va_list args, char *buffer, unsigned int index);
int print_hh_unsigned(va_list args, char *buffer, unsigned int index);
int print_hh_octal(va_list args, char *buffer, unsigned int index);
int print_hh_hexadecimal(va_list args, char *buffer, unsigned int index);
int print_uppercase_hh_hex(va_list args, char *buffer, unsigned int index);

int (*get_print_function(const char *specifier, int index))(va_list, char *, unsigned int);
int evaluate_print_function(const char *specifier, int index);
unsigned int handle_buffer(char *buffer, char character, unsigned int index);
int print_buffer(char *buffer, unsigned int buffer_size);
char *fill_binary_array(char *binary, long int num, int is_negative, int limit);
char *fill_octal_array(char *binary, char *octal);
char *fill_long_octal_array(char *binary, char *octal);
char *fill_short_octal_array(char *binary, char *octal);
char *fill_hexadecimal_array(char *binary, char *hex, int is_uppercase, int limit);

#endif
