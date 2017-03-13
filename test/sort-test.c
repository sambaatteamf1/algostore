#include <stdio.h>
#include <getopt.h>
#include "list.h"
#include "algo.h"
#include "util.h"

extern char *optarg;
extern int optind;
extern int optopt;
extern int opterr;
extern int optreset;


char dsTypes[][32] = {
	"dynamic-array",
	"static-array",	
	"list"
};

char algos[][32] = {
	"bubble",
	"selection",
	"insertion",
	"heap",
	"quick"
};

static struct option longopts[] = {

	{ "data-structure"	,  required_argument    ,       NULL,           'd' },
	{ "algo"			,  required_argument    ,       NULL,           'a' },
	{ "nitems"  	   	,  required_argument    ,       NULL,           'n' },
	{ "help"          	,  no_argument          ,       NULL,           'h' },
	{ NULL            	,  0                    ,       NULL,            0  }

};

/**
 * usage - prints usage for this process.
 */
static void usage(int argc, char* argv[])
{
    fprintf(stderr, "Usage: %s [-d --data-structure ] [ -n --nitems] [ -a --algo ] \n", argv[0]);
    fprintf(stderr, "-d :  list, dynamic-array, static-array. Default=dynamic-array\n");
    fprintf(stderr, "-a :  bubble,selection,insertion,heap,quick. Default:insertion\n");
    fprintf(stderr, "-n :  num items. Default=10  \n");
    return;
}


int main (int argc, char * argv[]) 
{
	
	int nitems = 10;
	char ch;
	char ds[32];
	char algo[32];
	bool dflag = false;
	bool aflag = false;

    /* parse command line */
    while ((ch = getopt_long(argc, argv, "d:n:a:",
                             longopts, NULL)) != -1)
        {
        switch (ch)
            {
            case 'a':
                strncpy(algo, optarg, sizeof(algo)-1);
                aflag = true;
                break;

            case 'd':
                strncpy(ds, optarg, sizeof(ds)-1);
                dflag = true;
                break;

            case 'n':
                nitems = atoi(optarg);
                break;

            case 'h':
            default:
                {
                usage(argc, argv);
                exit(0);
                }
            }
        }


	if (!dflag)
		strcpy(ds, "dynamic-array");

	if (!aflag)
		strcpy(algo, "insertion");

	if (!strcmp(ds, "list"))
	{
		List * l = NULL;

		l = create_int_list(nitems);

		fprintf(stdout, "Unsorted list\n");
		print_int_list(l);

		if (!strcmp(algo, "selection"))
			{
			list_selection_sort(l);
			}
		else if (!strcmp(algo, "bubble"))
			{
			list_bubble_sort(l);	
			}
		else
			{
			return -1;
			}

		fprintf(stdout, "sorted list using algo:%s sort\n", algo);
		print_int_list(l);		
	}
	else if (!strcmp(ds, "dynamic-array"))
	{
		Array * ar = NULL;

		ar = create_int_array(nitems);

		fprintf(stdout, "Unsorted array\n");
		print_int_array(ar);

		if (!strcmp(algo, "selection"))
			{
			array_selection_sort(ar);
			}
		else if (!strcmp(algo, "bubble"))
			{
			array_bubble_sort(ar);
			}
		else if (!strcmp(algo, "insertion"))
			{
			array_insertion_sort(ar);	
			}
		else
			{
			return -1;
			}

		fprintf(stdout, "sorted array using algo:%s sort\n", algo);
		print_int_array(ar);				
	}

	return 0;
}
