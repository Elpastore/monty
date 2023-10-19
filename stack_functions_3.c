#include "monty.h"
/**
 * pchar - function that print the first char of the top
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int letter;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	letter = (*stack)->n;

	if (letter < 0 || letter > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
		free_stack(stack);
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
 * rotl - function that rotates the stack to the top.
 * @stack: pointer to the stack
 * @line_number: line number of the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int value_1;

	(void)line_number;

	temp = *stack;
	if (temp != NULL)
		value_1 = temp->n;
	while (temp != NULL)
	{
		if (temp->next != NULL)
		{
			temp->n = temp->next->n;
		}
		else
		{
			temp->n = value_1;
		}
		temp = temp->next;
	}
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


