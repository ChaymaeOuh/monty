#include "monty.h"

/**
 * function_pall - Prints an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void function_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
