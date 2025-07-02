#ifndef clox_chunk_h
#define clox_chunk_h

#include <stdint.h>

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,  // 0
  OP_NEGATE,
  OP_RETURN,
} OpCode;
// this is the opration code which means each line which is translated has a
// operation code

typedef struct {
  int index;
  int capacity;
  uint8_t* code;  // is the operation code which is in hexadecical Ex: 0x1 ...
  int* lines;
  ConstPile constpile;
} Pile;
// Pile is the Bytecode that is to be  translated by the c virtual machine
void initPile(Pile* pile);
void writePile(Pile* pile, uint8_t byte, int line);
int addConst(Pile* pile, Consts constant);
void freepile(Pile* pile);

#endif
