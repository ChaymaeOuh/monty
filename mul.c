#include "monty.h"

/**
 * function_mul - Multiplies the second top element of the stack
 *                with the top element of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode
 */
void function_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	function_pop(stack, line_number);
}
