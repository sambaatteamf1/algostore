#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "list.h"

Array * array_selection_sort(Array * ar) 
	{
		ArrayIter ai;
		int * next = NULL;
		int * min = NULL;
		int * out = NULL;
		size_t mcursor = 0;
		size_t cursor = 0;
		
		while (cursor < array_size(ar))
		{
			array_iter_init(&ai, ar);
			while (array_iter_next(&ai, (void **)&next) != CC_ITER_END) 
			{
				// skip until the list is sorted
				if (array_iter_index(&ai) <= cursor)
				{
					min = next;		
					continue;				
				}

				if (*min > *next)
				{
					min = next;
					mcursor = array_iter_index(&ai);
				}
			}

			// swap 
			array_replace_at(ar, min, cursor, (void **)&out);
			array_replace_at(ar, out, mcursor, NULL);

			++cursor;
		}

		return ar;
	}

List * list_selection_sort(List * l) 
	{
		ListIter li;
		int * next = NULL;
		int * min = NULL;
		int * out = NULL;
		size_t mcursor = 0;
		size_t cursor = 0;
		
		while (cursor < list_size(l))
		{
			list_iter_init(&li, l);
			while (list_iter_next(&li, (void **)&next) != CC_ITER_END) 
			{
				// skip until the list is sorted
				if (list_iter_index(&li) <= cursor)
				{
					min = next;		
					continue;				
				}

				if (*min > *next)
				{
					min = next;
					mcursor = list_iter_index(&li);
				}
			}

			// swap 
			list_replace_at(l, min, cursor, (void **)&out);
			list_replace_at(l, out, mcursor, NULL);

			++cursor;
		}

		return l;
	}