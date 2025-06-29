#ifndef clox_vm_h
#define clox_vm_h

#include "common.h"
#include "pile.h"

typedef struct {
  Pile* vm_array;  // which is just pile or the address of pile array
  uint8_t* bp;     // byte pointer-bp
} VM;
typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretErrors;

void initVM();
InterpretErrors interpret(Pile* pile);
static InterpretErrors run();
void freeVM();

#endif
