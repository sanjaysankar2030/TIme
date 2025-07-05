#ifndef clox_vm_h
#define clox_vm_h

#include "common.h"
#include "pile.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
  Pile* vm_array;  // which is just pile or the address of pile array
  uint8_t* bp;     // byte pointer-bp
  Consts stack[STACK_MAX];
  Consts* sp;
} VM;
typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR
} InterpretErrors;

void initVM();
static void initstack();
InterpretErrors interpret(const char* code);
static InterpretErrors run();
void put(Consts input);
Consts pull();
void freeVM();

#endif
