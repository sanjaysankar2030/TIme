#include "common.h"
#include "debug.h"
#include "pile.h"

int main(int argc, const char* argv[]) {

  Pile pile ;
  initPile(&pile);
  writePile(&pile, OP_RETURN);
  disassemblePile(&pile, "test chunk");
  freepile(&pile);

  return 0;
}

