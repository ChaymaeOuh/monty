#include "monty.h"

/**
 * execute - Executes the opcode.
 * @content: Line content.
 * @stack: Double pointer to the head of the stack.
 * @counter: Line number.
 * @file: Pointer to the Monty file.
 * Return: 0 on success, 1 on failure.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", function_push},
		{"pall", function_pall},
		{"pint", function_pint},
		{"pop", function_pop},
		{"swap", function_swap},
		{"add", function_add},
		{"nop", function_nop},
                {"sub", function_sub},
		{"div", function_div},
                {"mul", function_mul},
		{"mod", function_mod},
		{"pchar", function_pchar},
		{"pstr", function_pstr},
		{"rotl", function_rotl},
		{"rotr", function_rotr},
		{"queue", function_queue},
		{"stack", function_stack},
		/* Add more opcodes here */
		{NULL, NULL}
	};
	char *opcode = strtok(content, " \n\t");
	int i;

	if (opcode && opcode[0] == '#')
		return 0;

	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, counter);
			return 0;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
