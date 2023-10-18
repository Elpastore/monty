#include "monty.h"

/**
 * add - function that add the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: the line number of the file
 */
void add(stack_t **stack, int line_number)
{
	int sum;
	int num_nodes;

	num_nodes = stack_len(*stack);
	/* printf("num_nodes: %i\n", num_nodes); */

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL || num_nodes < 2)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	/* printf("0stack->n %i\n0stack->next->n %i\n0sum %i\n", (*stack)->n, (*stack)->next->n, sum); */
	pop(stack, line_number);
	/* printf("1stack->n %i\n1stack->next->n %i\n1sum %i\n", (*stack)->n, (*stack)->next->n, sum); */
	(*stack)->n = sum;
	/* printf("2stack->n %i\n2stack->next->n %i\n2sum %i\n", (*stack)->n, (*stack)->next->n, sum); */
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
