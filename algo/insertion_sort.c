#include <stdlib.h>
#include <stdio.h>
#include "util.h"


Array * array_insertion_sort(Array * ar) 
	{
	ArrayIter sorted_ai;
	int *sorted_next;

	ArrayIter unsorted_ai;
	int *unsorted_next;

	/* start from the second element */
	array_iter_init(&unsorted_ai, ar);
	array_iter_next(&unsorted_ai, (void **)&unsorted_next);
	
	while (array_iter_next(&unsorted_ai, (void **)&unsorted_next) != CC_ITER_END) 
		{
		size_t index = array_iter_index(&unsorted_ai);
		size_t curr_index = 0;

		//fprintf(stdout, "unsorted index: %zu value:%d\n", index, *unsorted_next);
		
		array_iter_init(&sorted_ai, ar);

		while ((array_iter_next(&sorted_ai, (void **)&sorted_next) != CC_ITER_END) &&
			   ((curr_index = array_iter_index(&sorted_ai)) < index))
			{
			// fprintf(stdout, "sorted index: %zu value:%d < %d\n", curr_index, *sorted_next, *unsorted_next);

			if (*sorted_next > *unsorted_next)				
				{
				// fprintf(stdout, "move %d before %d\n", *unsorted_next, *sorted_next);
				/* swap elements */
				array_remove_at(ar, index, (void *)&unsorted_next);
				array_add_at(ar, (void *)unsorted_next, curr_index);
				break;
				}

			}
		}

	return ar;
	}
