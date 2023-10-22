#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MONTY_LEN 1024
/**
 * struct stack_s - doubly linked list representation of stack (or queue)
 * @n: it is integer
 * @prev: it points to previous element of stack (or queue)
 * @next: it points to next element of stack (or queue)
 *
 * Description: it is doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - it is opcode and function
 * @opcode: it is opcode
 * @f: function handle opcode
 *
 * Description: it is opcode and the function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 *struct info_s - it is info structure
 *@arg: it is argument
 *@file: it is file
 *@lNum: it is lnum
 *@fifo: it is fifo
 */

typedef struct info_s
{
	char *arg;
	FILE *file;
	unsigned int lNum;
	int fifo;
} info_t;

extern info_t infos;


/*monty.c*/
int main(int ac, char *av[]);
int instruction(char *opcode, stack_t **stack, unsigned int lNum);
void trimLeadingSpaces(char *str);
void condenseSpaces(char *str);
/*push.c*/
int is_digit(char c);
int is_valid_number(char *str);
void push(stack_t **head, unsigned int lNum);
/*pall.c*/
void pall(stack_t **head, unsigned int lNum);
/*free_stack.c*/
void free_stack(stack_t *head);
/*node_manipulation.c*/
void add_node(stack_t **head, int n);
void add_node_end(stack_t **head, int n);
/*pint.c*/
void pint(stack_t **head, unsigned int lNum);
/*pop.c*/
void pop(stack_t **head, unsigned int lNum);
/*swap.c*/
void swap(stack_t **head, unsigned int lNum);
/*math.c*/
void add(stack_t **head, unsigned int lNum);
void sub(stack_t **head, unsigned int lNum);
void mul(stack_t **head, unsigned int lNum);
void divi(stack_t **head, unsigned int lNum);
void mod(stack_t **head, unsigned int lNum);
/*nop*/
void nop(stack_t **head, unsigned int lNum);
/*pchar.c*/
void pchar(stack_t **head, unsigned int lNum);
/*pstr.c*/
void pstr(stack_t **head, unsigned int lNum);
/*rot.c*/
void rotl(stack_t **head, unsigned int lNum);
void rotr(stack_t **head, unsigned int lNum);
/*stack_queue.c*/
void queue(stack_t **head, unsigned int lNum);
void fstack(stack_t **head, unsigned int lNum);
#endif
