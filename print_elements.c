#include "monty.h"

/**
 *pall - it should print elements of doubly linked list.
 *@head: it is the head of list
 *@lNum: it is line number
 */

void pall(stack_t **head, unsigned int lNum)
{
	stack_t *current = *head;
	(void)lNum;

	if (!current)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
