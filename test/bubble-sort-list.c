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

static struct option longopts[] = {

	{ "data-structure"	,  required_argument    ,       NULL,           'd' },
	{ "nitems"  	   	,  required_argument    ,       NULL,           'n' },
	{ "help"          	,  no_argument          ,       NULL,           'h' },
	{ NULL            	,  0                    ,       NULL,            0  }

};

/**
 * usage - prints usage for this process.
 */
static void usage(int argc, char* argv[])
{
    fprintf(stderr, "Usage: %s [-d ] [ -n ] \n", argv[0]);
    fprintf(stderr, "-d :  list, dynamic-array, static-array. Default=list\n");
    fprintf(stderr, "-n :  num items. Default=10  \n");
    return;
}


int main (int argc, char * argv[]) 
{
	
	int nitems = 10;
	char ch;
	char ds[32];
	bool dflag = false;

    /* parse command line */
    while ((ch = getopt_long(argc, argv, "d:n:",
                             longopts, NULL)) != -1)
        {
        switch (ch)
            {
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
                break;
                }
            }
        }


	if (!dflag)
		strcpy(ds, "list");

	if (!strcmp(ds, "list"))
	{
		List * l = NULL;

		l = create_int_list(nitems);

		fprintf(stdout, "printing unsorted list\n");
		print_int_list(l);

		// list_bubble_sort(l);	
		list_selection_sort(l);

		fprintf(stdout, "print sorted list\n");
		print_int_list(l);		
	}
	else if (!strcmp(ds, "dynamic-array"))
	{
		Array * ar = NULL;

		ar = create_int_array(nitems);

		fprintf(stdout, "printing unsorted array\n");
		print_int_array(ar);

		array_bubble_sort(ar);

		fprintf(stdout, "print sorted array\n");
		print_int_array(ar);				
	}
	

	return 0;
}
