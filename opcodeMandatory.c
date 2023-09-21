#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void push(stack_t **doubly, unsigned int line)
{
	int n, k;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", line);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (k = 0; vglo.arg[k] != '\0'; k++)
	{
		if (!isdigit(vglo.arg[k]) && vglo.arg[k] != '-')
		{
			dprintf(2, "L%u: ", line);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	vglo.lifo == 1 ? add_dnodeint(doubly, n) : add_dnodeint_end(doubly, n);
}

/**
 * pall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @line: line numbers
 * Return: no return
 */
void pall(stack_t **doubly, unsigned int line)
{
	stack_t *current = *doubly;

	(void)line;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void pint(stack_t **doubly, unsigned int line)
{
	(void)line;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void pop(stack_t **doubly, unsigned int line)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	stack_t *aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @line: line number
 * Return: no return
 */
void swap(stack_t **doubly, unsigned int line)
{
	if (*doubly == NULL || (*doubly)->next == NULL)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	stack_t *first = *doubly;
	stack_t *second = first->next;

	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;

	*doubly = second;
}
