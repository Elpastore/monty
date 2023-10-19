#include "monty.h"
/**
 * pchar - function that print the first char of the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int letter;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	letter = (*stack)->n;

	if (letter < 0 || letter > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", letter);
}
