#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include <time.h>
#include "list.h"


Array * create_array(int nitems, int size) 
{
	Array * ar = NULL;
	int count = 0;

	ArrayConf conf;
	array_conf_init(&conf);

	conf.capacity = nitems;
	conf.exp_factor = 1;

	if (array_new_conf((ArrayConf const * const)&conf, &ar) != CC_OK) 
		{
		fprintf(stderr, "failed to create array\n");
		return NULL;
		}

	while (count < nitems) 
		{
		void * value = malloc(size);
		array_add(ar, value);
		++count;
		}

	return ar;
}

Array * create_int_array(int nitems) 
	{
	ArrayIter ai;
	int *next;
	time_t t;
	int defArr[] = { 5, 4, 9, 3, 2, 1, 8, 7, 0, 6 };
	int index;

	Array * ar = create_array(nitems, sizeof(int));

	srandom(time(&t));

	array_iter_init(&ai, ar);

	index = 0;
	while (array_iter_next(&ai, (void *)&next) != CC_ITER_END) 
		{
		if (index < 10)
			*next = defArr[index];
		else	
			*next = random() % nitems;

		++index;
		}

	return ar;
	}


void print_int_array(Array * ar) 
	{
	ArrayIter ai;
	int *next;

	array_iter_init(&ai, ar);

	while (array_iter_next(&ai, (void *)&next) != CC_ITER_END) 
		fprintf(stdout, "%d\n", *next);

	return;
	}


List * create_int_list(int nitems)
	{
	List * l = NULL;
	time_t t;
	int count = 0;

	if (list_new(&l) != CC_OK)
		{
		return NULL;							
		}

	srandom(time(&t));		

	while(count < nitems)
		{
		int * value = (int *)malloc(sizeof(int));
		*value = random() % nitems;
		list_add(l, value);
		++count;			
		}	

	return l;		
	}

void print_int_list(List * l) 
	{
	ListIter li;
	int *next;

	list_iter_init(&li, l);

	while (list_iter_next(&li, (void *)&next) != CC_ITER_END) 
		fprintf(stdout, "%d\n", *next);

	return;
	}
