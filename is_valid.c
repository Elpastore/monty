#include "monty.h"
/**
 * is_valid_integer -Checks if the given string represents a valid integer.
 * @str: string to be checked
 * Return: 1 if valid otherwise 0
 */
int is_valid_integer(char *str)
{
	if (*str == '-')
		str++; /*Skip the minus sign for negative numbers*/
	while (*str)
	{
		if (!isdigit(*str))
			return (0); /*Not a digit*/
		str++;
	}
	return (1); /*Valid integer*/
}
