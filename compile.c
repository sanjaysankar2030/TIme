#include "compile.h"

#include "common.h"
#include "scanner.h"

void compile(const char* code_buffer) {
  initScanner(code_buffer);
  int line_count = -1;
  for (;;) {
    Token token = scanToken();
    if (token.line != line) {
      printf("%4d ", token.line);
      line_count = token.line;
    } else {
      printf("   | ");
    }
    printf("%2d '%.*s'\n", token.t_type, token.length, token.start);

    if (token.t_type == TOKEN_EOF) break;
  }
}
