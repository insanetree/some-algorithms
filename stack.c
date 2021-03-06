#include "stack.h"
#include <stdlib.h>

stack* stack_init()
{
	stack* new_stack = malloc(sizeof(stack));
	if(new_stack != NULL)
	{
		new_stack->capacity = 0;
		new_stack->head = NULL;
	}
	return new_stack;
}

void push(stack* param_stack, void* param_data)
{
	struct stack_element* new_element = malloc(sizeof(struct stack_element));
	if(new_element != NULL)
	{
		
		new_element->data = param_data;
		new_element->next = param_stack->head;
		param_stack->head = new_element;
		param_stack->capacity++;
	}
}

void* top(stack* param_stack)
{
	return param_stack->head->data;
}

void pop(stack* param_stack)
{
	if(param_stack->capacity > 0)
	{
		struct stack_element* tmp = param_stack->head;
		param_stack->head = param_stack->head->next;
		free(tmp);
		param_stack->capacity--;
	}
}

void stack_delete(stack* param_stack)
{
	struct stack_element* current;
	while(param_stack->capacity > 0)
	{
		current = param_stack->head;
		param_stack->head = param_stack->head->next;
		free(current);
		param_stack->capacity--;
	}
}
