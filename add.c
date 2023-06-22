#include "monty.h"

/**
 * function_add - adds the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the instruction
 */
void function_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	function_pop(stack, line_number);
}
