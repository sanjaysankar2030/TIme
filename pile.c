#include <stdlib.h>

#include "pile.h"
#include "memory.h"

void initPile(Pile* pile){
    pile->index=0;
    pile->capacity=0;
    pile->code=NULL;
}
void writePile(Pile* pile,uint8_t byte){
    if (pile->index+1 > pile->capacity){
        int old_capacity=pile->capacity;
        pile->capacity=GROW_CAPACITY(old_capacity);
        pile->code=GROW_ARRAY(uint8_t,pile->code,old_capacity,pile->capacity);
    }

    pile->code[pile->index]=byte;
    pile->index++;
}

void freepile(Pile *pile){
    FREE_ARR(uint8_t, pile->code, pile->capacity);
    initPile(pile);
}
