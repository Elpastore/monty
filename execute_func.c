#include "monty.h"
/**
 * execute -function that execute specific function
 * @file: file descriptor
 */
void execute(FILE *file)
{
	size_t len = 0;
	char *line = NULL, *value_str;
	/* unsigned int line_number = 1; */
	unsigned int line_number = 0;
	char **tokens;
	int value;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		/* printf("line(%i)\n", line_number); */
		line_number++;
		if (line == NULL)
		{
			fflush(stdout);
			fprintf(stderr, "Error: malloc failed\n");
			free(line);
			free_stack(&stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		if (line[0] == '#')
			continue;
		tokens = tokenize(line);
		if (tokens == NULL) /*Empty line*/
			continue;

		if (strcmp(tokens[0], "push") == 0)
		{
			value_str = tokens[1];
			if (value_str == NULL || !is_valid_integer(value_str))
			{
				fflush(stdout);
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				/* fflush(stderr); */
				free(line);
				free_array(tokens);
				free_stack(&stack);
				/*free(value_str);*/
				exit(EXIT_FAILURE);
			}

			value = atoi(value_str);
			push(&stack, line_number, value);
		}
		/* else if (strcmp(tokens[0], "pall") == 0) */
		/* 	pall(&stack, line_number); */

		/* else if (strcmp(tokens[0], "swap") == 0) */
		/* 	swap(&stack, line_number); */

		/* else if (strcmp(tokens[0], "pint") == 0) */
		/* 	pint(&stack, line_number); */

		/* else if (strcmp(tokens[0], "pop") == 0) */
		/* 	pop(&stack, line_number); */

		/* else if (strcmp(tokens[0], "add") == 0) */
		/* 	add(&stack, line_number); */

		/* else if (strcmp(tokens[0], "nop") == 0) */
		/* 	nop(&stack, line_number); */

		/* else if (strcmp(tokens[0], "sub") == 0) */
		/* 	sub(&stack, line_number); */

		/* else if (strcmp(tokens[0], "div") == 0) */
		/* 	divide(&stack, line_number); */

		/* else if (strcmp(tokens[0], "mul") == 0) */
		/* 	mul(&stack, line_number); */

		/* else if (strcmp(tokens[0], "mod") == 0) */
		/* 	modulo(&stack, line_number); */

		/* else if (strcmp(tokens[0], "pchar") == 0) */
		/* 	pchar(&stack, line_number); */

		/* else if (strcmp(tokens[0], "rotl") == 0) */
		/* 	rotl(&stack, line_number); */

		/* else if (strcmp(tokens[0], "pstr") == 0) */
		/* 	pstr(&stack, line_number); */

		/* else if (strcmp(tokens[0], "rotr") == 0) */
		/* 	rotr(&stack, line_number); */

		else if (select_opcodes(tokens, &stack, line_number) == 1)
		{
			/*Unknown opcode*/
			fflush(stdout);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
			free(line);
			free_array(tokens);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
		/* line_number++; */
		free_array(tokens);
	}
	free(line);
	free_stack(&stack);
}
