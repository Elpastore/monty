#include "monty.h"

/**
 * add - function that add the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: the line number of the file
 */
void add(stack_t **stack, int line_number)
{
	/* int sum; */
	int num_nodes;

	num_nodes = stack_len(*stack);
	/* printf("num_nodes1: %i\n", num_nodes); */

	if (stack == NULL || *stack == NULL || num_nodes < 2)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* sum = (*stack)->n + (*stack)->next->n; */
	/* pop(stack, line_number); */
	/* (*stack)->n = sum; */

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);

	/* printf("num_nodes2: %i\n", stack_len(*stack)); */
}

/**
 * pop - reoves the top elemtn of the stack
 * @stack: the pointer to the stack  items
 * @line_number: line number of the monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	*stack = current->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(current);
}
/**
 * nop - nop opcode implementation
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

