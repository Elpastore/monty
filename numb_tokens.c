#include "monty.h"
/**
 * find_tok_numb -function that count the number of tokens
 * @line: line to be tokenized
 * Return: the number of tokens
 */
int find_tok_numb(char *line)
{
	char *cp_line = NULL, *token;
	int numb_token = 0;

	if (line == NULL)
	{
		return (0);
	}
	cp_line = strdup(line);
	token = strtok(cp_line, " \t\n");
	if (token == NULL)
	{
		free(line), line =  NULL;
		free(cp_line), cp_line = NULL;
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		numb_token++;
		token = strtok(NULL, " \t\n");
	}
	free(cp_line);
	return (numb_token);
}
