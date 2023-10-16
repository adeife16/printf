#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
/**
 * fill_hex_point_array - converts pointer array to a hexadecimal string
 * @binary_array: array where binary data is stored
 * @hexadecimal_string: array where the hexadecimal string will be stored
 * @size: size of the hexadecimal string
 * @ptr: pointer address
 *
 * Return: the hexadecimal string.
 */


char* fill_hex_array_for_pointer(void *ptr, char *hexadecimal, size_t size) {
    const uint8_t *data = (const uint8_t *)ptr; // Treat the data as bytes

    if (hexadecimal == NULL) {
        return NULL; // Invalid buffer
    }

    for (size_t i = 0; i < size; i++) {
        // Convert each byte to a two-character hexadecimal representation
        snprintf(&hexadecimal[i * 2], 3, "%02X", data[i]);
    }

    hexadecimal[size * 2] = '\0'; // Null-terminate the string

    return hexadecimal;
}
