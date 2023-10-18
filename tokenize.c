#include "monty.h"
/**
 * tokenize - function that tokenize the given line
 * @line: input to be tokenized
 * Return: array of tokens
 */
char **tokenize(char *line)
{
	char *token, **tokens;
	int i = 0, numb_tok;

	numb_tok = find_tok_numb(line);
	tokens = malloc((sizeof(char *) * (numb_tok + 1)));
	if (tokens == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
