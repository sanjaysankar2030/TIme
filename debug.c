// used to debug i.e test cases
#include "debug.h"

#include <stdint.h>
#include <stdio.h>

#include "common.h"
#include "pile.h"

void disassemblePile(Pile* pile, const char* name) {
  printf("_____%s_____\n", name);

  for (int offset = 0; offset < pile->index;) {
    offset = disassembleInstruction(pile, offset);
  }
}
int disassembleInstruction(Pile* pile, int offset) {
  printf("%04d ", offset);

  if (offset > 0 && pile->lines[offset] == pile->lines[offset - 1]) {
    printf("   | ");
  } else {
    printf("%4d ", pile->lines[offset]);
  }

  uint8_t instruction = pile->code[offset];

  switch (instruction) {
    case OP_CONSTANT:
      return constantInstruction("OP_CONSTANT", pile, offset);
    case OP_RETURN:
      return simpleInstruction("OP_RETURN", offset);

    default:
      printf("Unkown OpCodei %d", instruction);
      return offset + 1;
  }
}
static int simpleInstruction(const char* operation, int offset) {
  printf("%s\n", operation);
  return offset + 1;
}
static int constantInstruction(const char* name, Pile* pile, int offset) {
  uint8_t const_index = pile->code[offset + 1];
  printf("%s %04d   ", name, const_index);
  printConst(pile->constpile.const_arr[const_index]);
  return offset + 2;
}
void printConst(Consts value) { printf("%g\n", value); }
