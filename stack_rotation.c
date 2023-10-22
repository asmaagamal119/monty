#include "monty.h"

/**
 *rotl - it should rotate stack to top.
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void rotl(stack_t **head, __attribute__((unused)) unsigned int lNum)
{
	stack_t *temp, *rot;

	if (!*head || !(*head)->next)
		return;
	temp = *head;
	rot = (*head)->next;
	rot->prev = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	*head = rot;
}

/**
 *rotr - it should rotate stack to bottom.
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void rotr(stack_t **head, __attribute__((unused)) unsigned int lNum)
{
	stack_t *temp;

	if (!*head || !(*head)->next)
		return;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;

}
