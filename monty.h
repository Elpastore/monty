#ifndef MONTY_H
#define MONTY_H


#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);
void execute(FILE *file);
int is_valid_integer(char *str);
char **tokenize(char *line);
int find_tok_numb(char *line);
void free_array(char **tokens);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void modulo(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
int stack_len(const stack_t *head);
void rotl(stack_t **stack, unsigned int line_number);
void stack_op(stack_t **stack, unsigned int line_number);
void queue_op(stack_t **stack, unsigned int line_number);
int select_opcodes(char **tokens, stack_t **stack, unsigned int line_number);
void free_close_exit(char *line, stack_t *stack, FILE *file);

extern int mode;

#endif
