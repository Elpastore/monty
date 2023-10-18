#include "monty.h"
/**
* execute_script - Execute the Monty script
* @script_path: Path to the Monty script file
*/
void execute_script(const char *script_path)
{
	FILE *file;
	char *line = NULL;
	stack_t *global_stack = NULL;
    	char *opcode;
	int i;

	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;

	instruction_t instructions[] =
	{
		{"push", push},
		{"pall", pall},
		/* Add more opcodes as needed */
		{NULL, NULL}
	};

	/*Open the file*/
	file = fopen(script_path, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", script_path);
		exit(EXIT_FAILURE);
	}

	/* Read and execute each line of the file*/
	while ((read = getline(&line, &len, file)) != -1)
    {
		line_number++;

		/*Tokenize the line to get the opcode*/
		opcode = strtok(line, " \n\t");

		if (opcode == NULL || opcode[0] == '#')
		{
			continue; /*Ignore empty lines and comments*/
		}

		/* Find the corresponding function for the opcode*/
		i = 0;

		while (instructions[i].opcode)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&global_stack, line_number);
				break;
			}
			i++;
		}

		/* Handle unknown instruction*/
		if (!instructions[i].opcode)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free(line);
			free_stack(global_stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	/*Clean up and close the file*/
	free(line);
	free_stack(global_stack);
	fclose(file);
}
