#include "monty.h"

/**
 *add_node - it must add node at beginning
 *@head: it is head of list
 *@n: it is data of node
 *Return: it pointers to new head
 */

void add_node(stack_t **head, int n)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	temp->prev = NULL;
	temp->next = *head;
	if (*head)
		(*head)->prev = temp;
	*head = temp;
}

/**
 *add_node_end - it adds nod at end
 *@head: it is head of list
 *@n: it is data
 *Return: it must return  pointer
 */

void add_node_end(stack_t **head, int n)
{
	stack_t *temp, *end;

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	temp->next = NULL;
	temp->n = n;
	if (!*head)
	{
		temp->prev = NULL;
		*head = temp;
		return;
	}
	end = *head;
	while (end->next)
		end = end->next;
	end->next = temp;
	temp->prev = end;
}
