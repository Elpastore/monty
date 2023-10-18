#include "monty.h"
/**
* push - push opcode implementation
* @stack: pointer to the stack
* @line_number: line number in the file
*/
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;
	char *arg = strtok(NULL, " \n\t");

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack), stack = NULL;
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer */
	value = atoi(arg);

	/* Create a new stack node */
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack), stack = NULL;
		free(new_node);
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node */
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
* pall - pall opcode implementation
* @stack: pointer to the stack
* @line_number: line number in the file
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
* free_stack - free the stack
* @stack: pointer to the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *temp;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
