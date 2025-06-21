#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include <stdint.h>

typedef enum {
  OP_RETURN,//->0
} OpCode;
//this is the opration code which means each line which is translated has a
//operation code 

typedef struct{
    int index;
    int capacity;
    uint8_t* code;//is the operation code which is in hexadecical Ex: 0x1 ...
}Pile;
//Pile is the Bytecode that is to be  translated by the c virtual machine
void initPile(Pile* pile);
void writePile(Pile* pile,uint8_t byte);
void freepile(Pile* pile);
#endif
