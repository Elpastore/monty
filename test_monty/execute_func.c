#include "monty.h"
/**
 * execute -function that execute specific function
 * @file: file descriptor
 */
void execute(FILE *file)
{
	size_t len = 0;
	char *line = NULL;
	unsigned int line_number = 1;
	char *token;
	stack_t *global_stack = NULL;
	int i = 0;

	instruction_t instructions[] =
	{
		{"push", push},
		{"pall", pall},
		/* Add more opcodes as needed */
		{NULL, NULL}
	};

	while (getline(&line, &len, file) != -1)
	{
		token = strtok(line, " \t\n");
		if (token == NULL || token[0] == '#') /*Empty line or comments*/
			continue;
		
		while (instructions[i].opcode)
		{
			if (strcmp(token, instructions[i].opcode) == 0)
			{
				instructions[i].f(&global_stack, line_number);
				break;
			}
			i++;
		}

		/* Handle unknown instruction*/
		if (!instructions[i].opcode)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
			free(line);
			free_stack(&global_stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	free_stack(&global_stack);
}
