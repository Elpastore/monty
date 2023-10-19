#include "monty.h"


int select_opcodes(char **tokens, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"swap", swap},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", modulo},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};


	int i = 0;


	/* printf("entered select\n"); */
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		/* printf("entered for\n"); */
		if (strcmp(tokens[0], instructions[i].opcode) == 0)
		{
			/* printf("entered comparisons\n"); */
			instructions[i].f(stack, line_number);
			return (0); /* success */
		}
	}

	return (1); /* fail */
}
