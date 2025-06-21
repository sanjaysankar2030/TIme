#include<stdlib.h>


#include "memory.h"

void* reallocate(void* array,size_t old_count,size_t new_count){
    if(new_count==0){
        free(array);
        return NULL;
    }

    void* result = realloc(array,new_count );
     if (result == NULL) exit(1);
    return result;
}
