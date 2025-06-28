#ifndef clox_vm_h
#define clox_vm_h

#include "pile.h"

typedef struct {
  Pile* vm_array;//which is just pile or the address of pile array
} VM;
typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
}InterpretErrors;

void initVM();
InterpretErrors interpret(Pile* pile);
void freeVM();

#endif
