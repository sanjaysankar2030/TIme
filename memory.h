#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"
#include <stddef.h>

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type,array,old_count,new_count)\
    (type*)reallocate(array,sizeof(type)*old_count),\
     sizeof(type)*new_count

#define FREE_ARR(type,array,old_count)\
    reallocate(array,sizeof(type)*old_count,0)

void* reallocate(void* array,size_t old_count,size_t new_count);
#endif
//is a localvariable in heap too?
