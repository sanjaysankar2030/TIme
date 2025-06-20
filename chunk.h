#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include <stdint.h>

typedef enum {
  OP_RETURN,
} OpCode;

typedef struct{
    uint8_t* code;
}Pile;

#endif
