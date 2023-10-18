#include "monty.h"
/**
 * execute -function that execute specific function
 * @file: file descriptor
 */
void execute(FILE *file)
{
	size_t len = 0;
	char *line = NULL, *value_str;
	unsigned int line_number = 1;
	char **tokens;
	int value;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		tokens = tokenize(line);
		if (tokens == NULL) /*Empty line*/
			continue;
		if (strcmp(tokens[0], "push") == 0)
		{
			value_str = tokens[1];
			if (value_str == NULL || !is_valid_integer(value_str))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(line);
				free_array(tokens);
				free_stack(&stack);
				/*free(value_str);*/
				exit(EXIT_FAILURE);
			}

			value = atoi(value_str);
			push(&stack, line_number, value);
		}
		else if (strcmp(tokens[0], "pall") == 0)
			pall(&stack, line_number);

		else if (strcmp(tokens[0], "swap") == 0)
			swap(&stack, line_number);

		else if (strcmp(tokens[0], "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(tokens[0], "pop") == 0)
			pop(&stack, line_number);
		else if (strcmp(tokens[0], "add") == 0)
			add(&stack, line_number);

		else
		{
			/*Unknown opcode*/
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
			free(line);
			free_stack(&stack);
			free_array(tokens);
			exit(EXIT_FAILURE);
		}
		line_number++;
		free_array(tokens);
	}
	free(line);
	free_stack(&stack);
}
