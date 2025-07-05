#include "vm.h"

/* #include <cstdio> */

/* #include <math.h> */

#include "common.h"
#include "debug.h"
#include "pile.h"
#include "value.h"

VM vm;
void initVM() { initstack(); }
static void initstack() { vm.sp = vm.stack; }
void freeVM() {}

void put(Consts input) {
  *vm.sp = input;
  vm.sp++;
}

Consts pull() {
  vm.sp--;
  return *vm.sp;
}
InterpretErrors interpret(const char* code_buffer) {
  compile(code_buffer);
  return INTERPRET_OK;
}

static InterpretErrors run() {
#define READ_BYTE() (*vm.bp++)
#define READ_CONST() (vm.vm_array->constpile.const_arr[READ_BYTE()])
// for binary operations
#define BINARY_OP(op)  \
  do {                 \
    double b = pull(); \
    double a = pull(); \
    put(a op b);       \
  } while (0)
#define MODULO(op)                    \
  do {                                \
    double b = pull();                \
    double a = pull();                \
    double c = a - b * (long)(a / b); \
    put(c);                           \
  } while (0)

  for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
    printf("🚨 DEBUG TRACE IS ON 🚨\n");
    printf("                               ");
    for (Value* logger = vm.stack; logger < vm.sp; logger++) {
      printf("[");
      printConst(*logger);
      printf("]");
    }
    printf("\n");

    disassembleInstruction(vm.vm_array, (int)(vm.ip - vm.vm_array->code));
    // used to determine the offset
#endif

    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Consts constant = READ_CONST();
        put(constant);
        break;
      }
      case OP_NEGATE: {
        put(-pull());
        break;
      }
      case OP_ADD: {
        BINARY_OP(+);
        break;
      }
      case OP_SUB: {
        BINARY_OP(-);
        break;
      }
      case OP_MULT: {
        BINARY_OP(*);
        break;
      }
      case OP_DIV: {
        BINARY_OP(/);
        break;
      }
      /* case OP_MOD: { */
      /*   MODULO(%); */
      /*   break; */
      /* } */
      case OP_RETURN: {
        printConst(pull());
        return INTERPRET_OK;
      }
    }
  }
#undef READ_BYTE
#undef READ_CONST
}
