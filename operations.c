#include "monty.h"
/**
 * node_sub - The opcode sub subtracts the top element of the second element
 * @stack: head stack
 * @line_number: line number
 */
void node_sub(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = ((*stack)->next)->n - (*stack)->n;

	node_pop(stack, line_number);
	(*stack)->n = sub;
}
/**
 *node_mul - multiplies the top two elements in the stack
 * @stack: head stack
 * @line_number: line number
 */
void node_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
        int a, len = 0;

        for (aux = *stack; aux; aux = aux->next)
                len++;
        if (len < 2)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n",
                        line_number);
                exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	node_pop(stack, line_number);
	(*stack)->n *= a;
}

/**
 * node_nop - function that does nothing
 * @stack: head stack
 * @line_number: line number
 */
void node_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
