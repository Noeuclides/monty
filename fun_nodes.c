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

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (number == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: usage: push integer\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	np = atoi(number);
	node->n = np;
	if (*stack == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = *stack;
		node->prev = NULL;
		(*stack)->prev = node;
	}
	*stack = node;
}

/**
 * pall - print stack
 * @stack: head stack
 * @line_number: number of line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;

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
	stack_t *aux;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		aux = (*stack)->next;
		free(*stack);
		(*stack) = aux;
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * node_pint - print value of top
 * @stack: head stack
 * @line_number: line number
 */
void node_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}


}


/**
 * node_swap - swaps  two elements.
 * @stack: head stack
 * @line_number: line number of the file
 */

void node_swap(stack_t **stack, unsigned int line_number)
{
	int aux = 0;
	unsigned int l;

	l = line_number;

	if ((stack == NULL) || (*stack == NULL) || ((*stack)->next) == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = aux;
}
