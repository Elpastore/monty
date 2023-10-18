#include "monty.h"

/**
 * main - entry point of the  program
 * @argc: number of arguments
 * @argv: array that contains arguments
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	/*ssize_t read;*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	execute(file);
	fclose(file);

	return (0);
}
