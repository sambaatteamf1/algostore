#ifndef __UTIL_H
#define __UTIL_H

#include "array.h"
#include "list.h"

extern Array * create_array(int nitems, int size);
extern Array * create_int_array(int nitems);
extern void print_int_array(Array * ar);

extern List * create_int_list(int nitems);
extern void print_int_list(List * l);

#endif
