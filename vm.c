#include "vm.h"

/* #include <cstdio> */

/* #include <stdio.h> */

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
InterpretErrors interpret(Pile* pile) {
  vm.vm_array = pile;
  vm.bp = vm.vm_array->code;
  return run();
}

static InterpretErrors run() {
#define READ_BYTE() (*vm.bp++)
#define READ_CONST() (vm.vm_array->constpile.const_arr[READ_BYTE()])

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
      case OP_RETURN: {
        printConst(pull());
        return INTERPRET_OK;
      }
    }
  }
#undef READ_BYTE
#undef READ_CONST
}
