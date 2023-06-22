#include "monty.h"

void function_rotr(stack_t **stack, unsigned int counter)
{
    stack_t *current = *stack;

    (void)counter; /* Unused parameter */

    if (*stack != NULL && (*stack)->next != NULL)
    {
        while (current->next != NULL)
            current = current->next;
        current->next = *stack;
        (*stack)->prev = current;
        *stack = current->next;
        (*stack)->prev->next = NULL;
        (*stack)->prev = NULL;
    }
}
