#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @line: line number;
 * Return: no return
 */
void queue(stack_t **doubly, unsigned int line)
{
	(void)doubly;
	(void)line;

	vglo.lifo = 0;
}

/**
 * stack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @line: line number;
 * Return: no return
 */
void stack(stack_t **doubly, unsigned int line)
{
	(void)doubly;
	(void)line;

	vglo.lifo = 1;
}

/**
 * add - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line: line number;
 * Return: no return
 */
void add(stack_t **doubly, unsigned int line)
{
	if (*doubly == NULL || (*doubly)->next == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	(*doubly)->next->n += (*doubly)->n;
	pop(doubly, line);
}

/**
 * nop - doesn't do anythinhg
 *
 * @doubly: head of the linked list
 * @line: line number;
 * Return: no return
 */
void nop(stack_t **doubly, unsigned int line)
{
	(void)doubly;
	(void)line;
}

/**
 * sub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @line: line number;
 * Return: no return
 */
void sub(stack_t **doubly, unsigned int line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	pop(doubly, line);
}
