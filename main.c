#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int print_len;
    int printf_len;
    unsigned int ui;
    void *addr;

    print_len = _printf("Let's try to printf a simple sentence.\n");
    printf_len = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe63;
    _printf("Length:[%d, %i]\n", print_len, print_len);
    printf("Length:[%d, %i]\n", printf_len, printf_len);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    print_len = _printf("Percent:[%%]\n");
    printf_len = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", print_len);
    printf("Len:[%d]\n", printf_len);
    _printf("Unknown:[%r]\n");
    /*printf("Unknown:[%r]\n");*/
    return (0);
}
