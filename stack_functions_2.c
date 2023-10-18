#include "monty.h"
/**
 * add - function that add the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: the line number of the file
 */
void add(stack_t **stack, int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}
/**
 * pop - reoves the top elemtn of the stack
 * @stack: the pointer to the stack  items
 * @line_number: line number of the monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop and empty stack\n", line_number);
		exit(EXIT_FAILURE);
		/*return;*/
	}
	if (current != NULL)
	{
		*stack = current->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		free(current);
		/*return;*/
	}

}
