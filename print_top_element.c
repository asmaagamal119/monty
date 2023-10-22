#include "monty.h"

/**
 *pint -it should print elements of doubly linked list.
 *@head: it is the head of list
 *@lNum: it is line number
 */

void pint(stack_t **head, unsigned int lNum)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
