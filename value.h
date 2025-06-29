#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Consts;
typedef struct {
  int index;
  int capacity;
  Consts* const_arr;
} ConstPile;

void initConstPIle(ConstPile* constpile);
void writeConstPIle(ConstPile* constpile, Consts value);
void freeConstPIle(ConstPile* constpile);
void printConst(Consts value);
#endif
