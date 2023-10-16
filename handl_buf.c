#include "main.h"

/**
 * handle_buffer - concatenates the buffer characters
 * @buffer: buffer pointer
 * @character: character to concatenate
 * @index: index of buffer pointer
 *
 * Return: index of the buffer pointer.
 */
unsigned int handle_buffer(char *buffer, char character, unsigned int index)
{
    if (index == 1024)
    {
        print_buffer(buffer, index);
        index = 0;
    }
    buffer[index] = character;
    index++;
    return index;
}