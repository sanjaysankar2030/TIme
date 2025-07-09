
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "debug.h"
#include "pile.h"
#include "vm.h"

static void repl() {
  char verses[256];

  for (;;) {
    printf("B==D ");
    if (!fgets(verses, sizeof(verses), stdin)) {
      printf("\n");
      break;
    } else {
      interpret(verses);
    }
  }
}

static char* readfile(const char* path) { /* Read the file */
  FILE* fp = fopen(path, "rb");

  if (fp == NULL) { /* Null exeption */
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(74);
  }

  fseek(fp, 0L, SEEK_END);
  size_t filesize = ftell(fp);
  rewind(fp);

  char* buffer =
      (char*)malloc(filesize + 1);  // reading the bytes to the string

  if (buffer == NULL) { /* case checking */
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(74);
  }
  size_t buffersize = fread(buffer, sizeof(char), filesize, fp);
  /* reading the file to the string */
  buffer[buffersize] = '\0';

  if (buffersize < filesize) { /* case check */
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }

  fclose(fp);
  return buffer;
}

/* Running the file -> calling readfile() */
static void runfile(const char* path) {
  char* code = readfile(path);
  InterpretErrors result = interpret(code);
  free(code);

  if (result == INTERPRET_COMPILE_ERROR) exit(65);
  if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, const char* argv[]) {  // main
  initVM();
  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    runfile(argv[1]);
  } else {
    fprintf(stderr, "Usage: clox[path]/n");
    exit(64);
  }

  freeVM();

  return 0;
}
