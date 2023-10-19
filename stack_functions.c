#include "monty.h"
int mode = 0; /* Intialize as stack mode by defauld*/
/**
 * push - function that add items at the top af the stack
 * @stack: the pointer to the stack  items
 * @line_number: line number of the monty file
 * @value: value to be added
 */

void push(stack_t **stack, unsigned int line_number, int value)
{

	stack_t *current;
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_number;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	
	if (mode == 0)
	{
		/* Stack mode LIFO*/
		new_node->next = *stack;

		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		/*Queue mode FIFO*/
		current = *stack;
		if (current != NULL)
		{
			while (current->next != NULL)
			{
				current = current->next;
			}
			current->next = new_node;
			new_node->next = NULL;
			new_node->prev = current;
		}
		else
		{
			*stack = new_node;
			new_node->next = NULL;
		}
	}
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
 * swap - function that swap two element of the the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int n1, n2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	n1 = (*stack)->n;
	n2 = (*stack)->next->n;

	(*stack)->n = n2;
	(*stack)->next->n = n1;
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

/**
 * pint - prints the value at the top of the stack, then newline
 * @stack: the pointer to the stack  items
 * @line_number: line number of the monty file
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		/* perror("L%d: can't pint, stack empty\n", line_number); */
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	if (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
