#include "monty.h"

/**
 * free_close_exit - frees line, stack, fcloses and then exits
 * @line: the line we are on
 * @stack: the stack we are working with
 * @file: the file we are reading
 */

void free_close_exit(char *line, stack_t *stack, FILE *file)
{
	free(line);
	free_stack(&stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
 * execute -function that execute specific function
 * @file: file descriptor
 */
void execute(FILE *file)
{
	size_t len = 0;
	char *line = NULL, *value_str;
	unsigned int line_number = 0;
	char **tokens;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		if (line == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_close_exit(line, stack, file);
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
				free(value_str);
				free_close_exit(line, stack, file);
			}
			push(&stack, line_number, atoi(value_str));
		}
		else if (select_opcodes(tokens, &stack, line_number) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
			free_close_exit(line, stack, file);
		}
		free_array(tokens);
	}
	free(line);
	free_stack(&stack);
}
