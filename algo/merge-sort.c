#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include <math.h>

static Array * array_merge(Array * first, Array * second)
{
	Array * merged = NULL;
	size_t first_size = 0;
	size_t second_size = 0;
	size_t n;
	size_t f_index = 0;
	size_t s_index = 0;

	if (!second) return first;
	if (!first) return second;

	first_size = array_size(first);
	second_size = array_size(second);

	n = first_size + second_size;

	array_new(&merged);
	
	while ((f_index + s_index) < n)
	{
		int * ele1 = NULL;
		int * ele2 = NULL;

		array_get_at(first,  f_index, (void **)&ele1);
		array_get_at(second, s_index, (void **)&ele2);

		if (!ele1) 
		{
			array_add(merged, ele2);
			++s_index;
			continue;
		}

		if (!ele2) 
		{
			array_add(merged, ele1);	 
			++f_index;
			continue;
		}

		if (*ele1 <= *ele2)
		{
			array_add(merged, ele1);
			++f_index;
		}
		else
		{
			array_add(merged, ele2);
			++s_index;
		}

	}

	return merged;
}

static Array * split_and_merge(Array * ar, size_t start, size_t end)
{
	Array * new = NULL;
	Array * first = NULL;
	Array * second = NULL;
	size_t n;

	n =  end - start + 1;

	// fprintf(stdout, "sub-array has (%zu - %zu) %zu elements\n", start, end, n);

	if (n == 1)
	{
		array_subarray(ar, start-1, end-1, &new);
		return new;		
	}
	
	first = split_and_merge(ar, start, (start + n/2 - 1));
	second = split_and_merge(ar, (start + n/2), end);
	
	if (first)
	{
		// fprintf(stdout, "first sub-array \n");
		// print_int_array(first);		
	}

	if (second)
	{
		// fprintf(stdout, "second sub-array \n");
		// print_int_array(second);
	}

	new = array_merge(first, second);

	// fprintf(stdout, "merged sub-array \n");
	// print_int_array(new);
	

	return new;
}

Array * array_merge_sort(Array * ar)
{
	return split_and_merge(ar, 1, array_size(ar));
}