#include "monty.h"

/**
 *is_digit - it should check if it is digit
 *@c: one to checked
 *Return: it is digit
 */

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 *is_valid_number - it should check if valid
 *@str: one to checked
 *Return: it must return 0 or 1 on success
 */

int is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (!is_digit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 *push - it should print all elements of doubly linked list.
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void push(stack_t **head, unsigned int lNum)
{
	int int_val, n;

	if (infos.arg == NULL || *infos.arg == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	int_val = atoi(infos.arg);
	n = is_valid_number(infos.arg);
	if ((int_val == 0 && strcmp(infos.arg, "0") != 0)  || n != 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (infos.fifo == 0)
		add_node(head, int_val);
	else
		add_node_end(head, int_val);
}
