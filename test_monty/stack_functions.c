#include "monty.h"
/**
 * push - function that add items at the top af the stack
 * @stack: the pointer to the stack  items
 * @line_number: line number of the monty file
 * @value: value to be added
 */

void push(stack_t **stack, unsigned int line_number)
{

	int value;
	char *arg = strtok(NULL, " \n\t");
	stack_t *new_node;

	if (arg == NULL || !is_valid_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		/*free(line);*/
		/*free_array(tokens);*/
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");

		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - function that print stack's items
 * @line_number: the line number of the monty file
 * @stack: the pointer to the stack  items
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (*stack ==  NULL)
	{
		return;
	}
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * free_stack - function to free the stack.
 * @stack: the pointer to the stack  items
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
