#include "monty.h"

/**
 * function_push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void function_push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!bus.arg || !isdigit(*bus.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	addnode(stack, n);
}
