#include "monty.h"
/**
 * add - function that add the top two elements of the stack.
 * @stack: pointer to the stack
 * @lin_number: the line number of the file
 */
void add(stack_t **stack, int line_number)
{
	int sum;

	if (stack == NULL || *stack== NULL || stack->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
