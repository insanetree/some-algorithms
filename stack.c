#include "stack.h"

stack* init_stack()
{
	stack* new_stack = malloc(sizeof(stack));
	new_stack->capacity = 0;
	new_stack->head = NULL;
	return new_stack;
}

void push(stack* param_stack, void* param_data)
{
	struct stack_element* new_element = malloc(sizeof(struct stack_element));
	new_element->data = param_data;
	new_element->next = param_stack->head;
	param_stack->capacity++;
}
