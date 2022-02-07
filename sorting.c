#include "sorting.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>


void* get_pivot(void* low, void* high, size_t size)
{
	unsigned long long n = (high-low)/size + 1; //get the number of elements in between
	unsigned long long i = rand() % n; //get random number form 0 to n-1
	return low + i*size;
}

void* qs_partition(void* low, void* high, size_t size, int(*cmp)(void*, void*))
{
	void* piv = get_pivot(low, high, size);
	void* i = low;
	void* j = high;
	void* tmp = malloc(size);
	while(i < j)
	{
		while(i < j && cmp(i, piv) <= 0)
		{
			i = i+size;
		}
		while(cmp(j, piv) > 0)
		{
			j = j-size;
		}
		if(i < j)
		{
			memcpy(tmp, i, size);
			memcpy(i, j, size);
			memcpy(j, tmp, size);
			if(j == piv)
			{
				piv = i;
			}
		}
	}
	memcpy(tmp, piv, size);
	memcpy(piv, j, size);
	memcpy(j, tmp, size);
	free(tmp);
	return j;
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
			push(bound, mid-size);
		}
		if(mid+size < high)
		{
			push(bound, mid+size);
			push(bound, high);
		}
	}
	stack_delete(bound);
}
