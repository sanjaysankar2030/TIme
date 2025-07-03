#include "common.h"
#include "debug.h"
#include "pile.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
  initVM();

  Pile pile;
  initPile(&pile);
  // adding constants to the const pile
  int const_index = addConst(&pile, 1.2);
  // wrinting the OP_CONSTANT to pile* pile
  writePile(&pile, OP_CONSTANT, 1);
  writePile(&pile, const_index, 1);

  const_index = addConst(&pile, 3.4);
  writePile(&pile, OP_CONSTANT, 1);
  writePile(&pile, const_index, 1);
  writePile(&pile, OP_ADD, 1);

  const_index = addConst(&pile, 5.6);
  writePile(&pile, OP_CONSTANT, 1);
  writePile(&pile, const_index, 1);
  writePile(&pile, OP_DIV, 1);

  writePile(&pile, OP_NEGATE, 1);

  /* writePile(&pile, OP_MOD, 1); */

  writePile(&pile, OP_RETURN, 1);
  disassemblePile(&pile, "test chunk");
  interpret(&pile);
  freeVM();
  freepile(&pile);

  return 0;
}
