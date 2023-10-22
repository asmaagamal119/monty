#include "monty.h"

/**
 *pop - it should remove last on stack
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void pop(stack_t **head, unsigned int lNum)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lNum);
		fclose(infos.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
