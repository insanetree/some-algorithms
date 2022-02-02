#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>

struct stack_element
{
	void* data;
	struct stack_element* next;
};

typedef struct stack
{
	struct stack_element* head;
	unsigned capacity;
}stack;

stack* init_stack();
void push(stack*, void*);
void* top(stack*);
void pop(stack*);
void stack_delete(stack*);

#endif //_STACK_H_
