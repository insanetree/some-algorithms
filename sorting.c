#include "sorting.h"
#include "stack.h"

void* qs_partition(void* low, void* high, size_t size, int(*cmp)(void*, void*))
{
	void* piv = NULL;
	//TODO
	return piv;
}

void quick_sort(void* arr, unsigned cnt, size_t size, int(*cmp)(void*, void*))
{
	void* low = arr; //pointer to a first element in array
	void* high = arr + (cnt-1)*size; //pointer to a last element in array
	void* mid;
	stack* bound = stack_init();
	push(bound, low); //addres of an element copied to stack
	push(bound, high);
	
	//PUSH LOW, THEN HIGH
	while(bound->capacity != 0)
	{
		high = top(bound);
		pop(bound);
		low = top(bound);
		pop(bound);
		mid = qs_partition(low, high, size, cmp);
		if(low < mid-size)
		{
			push(bound, low);
			push(bound, mid - size);
		}
		if(mid+size < high)
		{
			push(bound, mid+size);
			push(bound, high);
		}
	}
}
