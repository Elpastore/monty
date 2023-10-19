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

/**
 * sub - function that subtracts the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: the line number of the file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	difference = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = difference;
}

/**
 * mul - function that multiplies the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: the line number of the file
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int product;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	product = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = product;
}

/**
 * pstr - function that print the first char of the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *letter = *stack;

	(void) line_number;

	while (letter != NULL && letter->n > 0 && letter->n < 128)
	{
		fprintf(stdout, "%c", letter->n);
		letter = letter->next;
	}

	fprintf(stdout, "\n");
}



