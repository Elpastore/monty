#include "monty.h"

/**
 * stack_len -returns the number of elements in the stack
 * @head: current position in the stack
 *
 * Return: the number of nodes
 */


int stack_len(const stack_t *head)
{
	int num_nodes = 0;

	while (head != NULL)
	{
		num_nodes++;
		head = head->next;
	}

	return (num_nodes);
}
