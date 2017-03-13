#include <stdlib.h>
#include <stdio.h>
#include "util.h"

List * list_bubble_sort(List * l) 
	{
		bool swapped = true;

		while (swapped)
		{
			ListIter li;
			int * next = NULL;
			int * prev = NULL;
			
			swapped = false;

			list_iter_init(&li, l);
			while (list_iter_next(&li, (void **)&next) != CC_ITER_END) 
			{
				if (!prev)
				{
					prev = next;
					continue;
				}

				if (*prev > *next)
				{
					int tmp = *prev;
					
					*prev = *next;
					*next = tmp;
					swapped = true;
				}

				prev = next;
			}
		}

		return l;
	}

Array * array_bubble_sort(Array * ar)
	{
		bool swapped = true;

		while (swapped)
		{
			ArrayIter ai;
			int * next = NULL;
			int * prev = NULL;
			
			swapped = false;

			array_iter_init(&ai, ar);
			while (array_iter_next(&ai, (void **)&next) != CC_ITER_END) 
			{
				if (!prev)
				{
					prev = next;
					continue;
				}

				if (*prev > *next)
				{
					int tmp = *prev;
					
					*prev = *next;
					*next = tmp;
					swapped = true;
				}

				prev = next;
			}
		}

		return ar;
	}	