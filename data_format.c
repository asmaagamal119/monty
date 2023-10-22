#include "monty.h"

/**
 *fstack - it should set format of data to stack
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void fstack(stack_t **head, unsigned int lNum)
{
	(void)head;
	(void)lNum;
	infos.fifo = 0;
}

/**
 *queue - it should set format of data to queue
 *@head: it is the head of list
 *@lNum: it is the line number
 */

void queue(stack_t **head, unsigned int lNum)
{
	(void)head;
	(void)lNum;
	infos.fifo = 1;
}
