#include "monty.h"
/**
 * node_push - add node to de list
 * @stack: head stack
 * @line_number: number of line
 */
void node_push(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		printf(ERROR_MALLOC);
		exit(EXIT_FAILURE);
	}

	head->n = line_number;
	head->next = *stack;
	head->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = head;
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
 * @ln: line number
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
