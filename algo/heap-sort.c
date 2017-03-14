#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include <math.h>


#define LEFT_CHILD(n)	((2*n) + 1)
#define RIGHT_CHILD(n)  ((2*n) + 2)


static size_t check_max_heap(Array * ar, int * result)
{
	int index = 0;
	size_t count =  array_size(ar);
	bool voilated = false;

	while (index < count)
	{
		int * parent;
		int * left_child;
		int * right_child;
		int * max;

		array_get_at(ar, index, (void **)&parent);
		array_get_at(ar, LEFT_CHILD(index), (void **)&left_child);
		array_get_at(ar, RIGHT_CHILD(index), (void **)&right_child);
		
		if (left_child && right_child)
			max = *left_child > *right_child  ? left_child : right_child;
		else if (left_child)
			max = left_child;
		else if (right_child)
			max = right_child;

		if (*parent < *max)
		{
			// fprintf(stdout, "heap property voilated at:%d\n", index);
			voilated = true;
			break;
		}

		++index;
	}	

	if (voilated)
	{
		*result = index;
		return -1;
	}

	return 0;
}

static int build_max_heap(Array * ar, size_t start, size_t end)
{
	int index = 0;
	size_t count =  end - start; 

	// fprintf(stdout, "Building max heap for index range %zu-%zu\n", start, end);

	index = floor((count-1)/2);

	// fprintf(stdout, "Starting heapify from index: %d\n", index);

	while(index >= 0)
	{
		int * parent = NULL;
		int * left_child = NULL;
		int * right_child = NULL;
		int * max;

		// fprintf(stdout, "parent:%d left:%d right:%d\n", index, LEFT_CHILD(index), RIGHT_CHILD(index));

		array_get_at(ar, index, (void **)&parent);

		if (LEFT_CHILD(index) <= end)
			array_get_at(ar, LEFT_CHILD(index), (void **) &left_child);

		if (RIGHT_CHILD(index) <= end)
			array_get_at(ar, RIGHT_CHILD(index), (void **) &right_child);

		// find the max of the two children
		if (left_child && right_child)
			max = *left_child > *right_child  ? left_child : right_child;
		else if (left_child)
			max = left_child;
		else if (right_child)
			max = right_child;

		if ((*parent < *max) && (max == left_child))
		{
			// fprintf(stderr, "%s:%d swap: left child at index:%d with parent at index: %d\n", 
			// 		__func__, __LINE__, LEFT_CHILD(index), index);

			// swap left child with parent
			array_replace_at(ar, parent, LEFT_CHILD(index), (void **)&left_child);
			array_replace_at(ar, left_child, index, NULL);
		}
		else if ((*parent < *max) && (max == right_child))
		{
			// fprintf(stderr, "%s:%d swap: right child at index:%d with parent at index: %d\n", 
			// 		__func__, __LINE__, RIGHT_CHILD(index), index);

			// swap right child with parent
			array_replace_at(ar, parent, RIGHT_CHILD(index), (void **)&right_child);
			array_replace_at(ar, right_child, index, NULL);
		}

		index--;
	}

	return 0;
}


int array_heap_sort(Array * ar)
{
	size_t end = 0;
	size_t size =  array_size(ar);
	int index = 0;

	// get the index of the last element
	end = size - 1;

	while (end > 0)
	{
		int * root_value;
		int * end_value;

		// Build the heap so that largest value is at the root
		build_max_heap(ar, 0, end);

		// ar[0] is the root and largest value. The swap moves it in front of the sorted elements
		array_get_at(ar, end, (void **)&end_value);
		array_replace_at(ar, end_value, 0, (void **)&root_value);
		array_replace_at(ar, root_value, end, NULL);		

		if (!check_max_heap(ar, &index)) 
			break;

		end = end - 1;
	}

	return 0;

}
