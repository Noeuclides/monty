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
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	mul = ((*stack)->next)->n * (*stack)->n;
	node_pop(stack, line_number);
	(*stack)->n = mul;
}
/**
 * node_nop - function that does nothing
 * @stack: head stack
 * @line_number: line number
 */
void node_nop(stack_t **stack, unsigned int line_number)
{
	;
}
