#include "monty.h"
/**
 * stack_op - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: the line number of file
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	mode = 0;
}
/**
 * queue_op - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;

	mode = 1;
}
