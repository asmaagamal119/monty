#include "monty.h"

/**
 *free_stack - it should free doubly linked list.
 *@head: it is the head of list
 */

void free_stack(stack_t *head)
{
	stack_t *current, *next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
