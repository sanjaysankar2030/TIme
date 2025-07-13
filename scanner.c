#ifndef clox_scanner_h
#define clox_scanner_h

#include "scanner.h"

#include <stdbool.h>
#include <string.h>

typedef struct {
  const char* start;
  const char* current;
  int lines;
} Scanner;

Scanner scanner;

static bool isAtEnd() { return *scanner.current == '\0'; }

static Token giveToken(TokenType type) {
  Token token;
  token.t_type = type;
  token.start = scanner.start;
  token.length = (int)(scanner.current - scanner.start);
  token.lines = scanner.lines;
  return token;
}
static Token errorToken(const char* message) {
  Token token;
  token.t_type = TOKEN_ERROR;
  token.start = message;
  token.length = (int)strlen(message);
  token.lines = scanner.lines;
  return token;
}
void initScanner(const char* source) {
  scanner.start = source;
  scanner.current = source;
  scanner.lines = 1;
}
Token scanToken() {
  scanner.start = scanner.current;
  if (isAtEnd()) return giveToken(TOKEN_EOF);

  return errorToken("Unexpected char .");
}

#endif
