#include "monty.h"
/**
* main -entry point if the program
* @argc: number of arguments
* @argv: array of string storing arguments
* Return: success
*/
int main(int argc, char *argv[])
{
	/*Check if the correct number of arguments is provided*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/*Call the execute_script function with the script file path*/
	execute_script(argv[1]);

	return (EXIT_SUCCESS);
}
