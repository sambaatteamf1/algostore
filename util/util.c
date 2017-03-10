#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include <time.h>


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
	Array * ar = create_array(nitems, sizeof(int));

	srandom(time(&t));

	array_iter_init(&ai, ar);

	while (array_iter_next(&ai, (void *)&next) != CC_ITER_END) 
		{
		*next = random() % nitems;
		}

	return ar;
	}

