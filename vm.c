#include "vm.h"

#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "pile.h"

VM vm;
void initVM() {}
void freeVM() {}
InterpretErrors interpret(Pile *pile) {
  vm.vm_array = pile;
  vm.bp = vm.vm_array->code;
  return run();
}
static InterpretErrors run() {
#define READ_BYTE() (*vm.bp++)
#define READ_CONST() (vm.vm_array->constpile.const_arr[READ_BYTE()])
  for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
    disassembleInstruction(vm.vm_array, (int)(vm.ip - vm.vm_array->code));
    // used to determine the offset
#endif

    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Consts constant = READ_CONST();
        printConst(constant);
        printf("\n");
        break;
      }
      case OP_RETURN: {
        return INTERPRET_OK;
      }
    }
  }
#undef READ_BYTE
#undef READ_CONST
}
