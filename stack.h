#ifndef _STACK_H_
#define _STACK_H_

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

stack* stack_init();
void push(stack*, void*);
void* top(stack*);
void pop(stack*);
void stack_delete(stack*);

#endif //_STACK_H_
