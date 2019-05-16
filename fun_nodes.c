#include "monty.h"

/**
 * node_push - add node to de list
 * @stack: head stack
 * @line_number: number of line
 */
void node_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int np;

	(void)line_number;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}

	np = atoi(number);
	node->n = np;
	if (*stack == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		node->next = *stack;
		node->prev = NULL;
		(*stack)->prev = node;
		*stack = node;
	}
}

/**
 * pall - print stack
 * @stack: head stack
 * @line_number: number of line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	(void)line_number;

	for (aux = *stack; aux != NULL; aux = aux->next)
		printf("%i\n", aux->n);
}

/**
 * node_pop - removes the node
 * @stack: head stack
 * @line_number: line number
 */
void node_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;

	if (stack == NULL || *stack == NULL)
	{
		printf("L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = head->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(head);
}
/**
 * node_pint - print value of top
 * @stack: head stack
 * @line_number: line number
 */
void node_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		return;
	}

	printf("%d\n", head->n);
}
