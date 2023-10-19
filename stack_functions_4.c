#include "monty.h"

/**
 * rotr - function that rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *lastNode;

	(void)line_number;
	if (stack == NULL ||*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	lastNode = *stack;
	while (lastNode->next != NULL)
	{
		lastNode = lastNode->next;
	}
	lastNode->prev->next = NULL;
	lastNode->prev = NULL;
	lastNode->next = *stack;
	(*stack)->prev = lastNode;
	*stack = lastNode;
}
