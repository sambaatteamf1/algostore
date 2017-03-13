#ifndef __ALGO_H
#define __ALGO_H

#include "array.h"
#include "list.h"


extern List * list_bubble_sort(List *l);
extern List * list_selection_sort(List *l);

extern Array * array_bubble_sort(Array * ar);
extern Array * array_insertion_sort(Array * ar);
extern Array * array_selection_sort(Array * ar);
#endif
