#include "common.h"
#include "value.h"
#include "memory.h"

#include <stdlib.h>
#include <stdio.h>


void initConstPIle(ConstPile *constpile){

    constpile->index=0;
    constpile->capacity=0;
    constpile->const_arr=NULL;
}
void writeConstPIle(ConstPile *constpile, Consts value){

    if (constpile->capacity < constpile->index+1){
        int old_capacity=constpile->capacity;
        constpile->capacity=GROW_CAPACITY(old_capacity);
        constpile->const_arr=GROW_ARRAY(Consts, constpile->const_arr, old_capacity, constpile->capacity);
    }
    
    constpile->const_arr[constpile->index]=value;
    constpile->index++;
}

void freeConstPIle(ConstPile *constpile){
    FREE_ARR(Consts, constpile->const_arr, constpile->capacity);
    initConstPIle(constpile);
} 

