#include <stdlib.h>

#include "pile.h"
#include "memory.h"
#include "value.h"

void initPile(Pile* pile){
    pile->index=0;
    pile->capacity=0;
    pile->code=NULL;
    pile->lines=NULL;
    initConstPIle(&pile->constpile);

}
void writePile(Pile* pile,uint8_t byte,int line){
    if (pile->capacity < pile->index+1){
        int old_capacity=pile->capacity;
        pile->capacity=GROW_CAPACITY(old_capacity);
        pile->code=GROW_ARRAY(uint8_t,pile->code,old_capacity,pile->capacity);
        pile->lines=GROW_ARRAY(int,pile->lines,old_capacity,pile->capacity);
    }

    pile->code[pile->index]=byte;
    pile->lines[pile->index]=line;
    pile->index++;

}
int addConst(Pile *pile, Consts constant){
    writeConstPIle(&pile->constpile,constant  );
    return pile->constpile.index-1;
}

void freepile(Pile *pile){
    FREE_ARR(uint8_t, pile->code, pile->capacity);
    FREE_ARR(int, pile->lines, pile->capacity);
    freeConstPIle(&pile->constpile);
    initPile(pile);
}
