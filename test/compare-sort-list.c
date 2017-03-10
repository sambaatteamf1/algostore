#include <stdio.h>
#include "util.h"
#include "algo.h"

#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include <time.h>


void print_array(Array * ar) 
	{
	ArrayIter ai;
	int *next;

	array_iter_init(&ai, ar);

	while (array_iter_next(&ai, (void *)&next) != CC_ITER_END) 
		fprintf(stdout, "%d\n", *next);

	return;
	}


char dsTypes[][32] = {
	"dynamic-array",
	"static-array",
	"list"
};


int main (int argc, char * argv[]) 
	{
	Array * ar = NULL;
	int size = 10;
	
	if (argc > 1) 
		size = atoi(argv[1]);

	ar = create_int_array(size) ;

	//fprintf(stdout, "print unsorted array\n");
	//print_array(ar);
	array_insertion_sort(ar) ;

	//fprintf(stdout, "print sorted array\n");
	print_array(ar);

	return 0;
	}
