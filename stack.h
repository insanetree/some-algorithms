#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>

typedef struct stack_element
{
	void* data;
	struct stack_element* next;
};

typedef struct stack
{
	struct stack_element* head;
	int capacity;
}stack;


void push(stack*, void*);

#endif //_STACK_H_
