#include "monty.h"

void function_pchar(stack_t **stack, unsigned int counter)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", counter);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}
