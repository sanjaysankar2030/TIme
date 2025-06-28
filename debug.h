#ifndef clox_debug_h
#define clox_debug_h

#include "common.h"
#include "pile.h"
#include "value.h"

void disassemblePile(Pile* pile,const char* name);
int disassembleInstruction(Pile* pile, int offset);
static int simpleInstruction(const char* operation,int offset);
static int constantInstruction(const char* name,Pile* pile,int offset);
void printConst(Consts value);

#endif
