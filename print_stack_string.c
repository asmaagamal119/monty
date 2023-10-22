#include "monty.h"

/**
 *pstr - it should print string starting at top of stack
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void pstr(stack_t **head, unsigned int lNum)
{
	stack_t *temp;
	(void)lNum;

	temp = *head;
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
