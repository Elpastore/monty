#include "monty.h"
/**
 * is_number - check if a string is a valid integer
 * @str: string to check
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(const char *str)
{
    if (!str || *str == '\0')
        return 0;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}