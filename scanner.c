#ifndef clox_scanner_h
#define clox_scanner_h

#include "scanner.h"

#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  const char* start;
  const char* current;
  int lines;
} Scanner;

Scanner scanner;

static char advance() {
  scanner.current++;
  return scanner.current[-1];
}

static bool isAtEnd() {
  return *scanner.current == '\0';
}  // Leaves null
   // values

static bool match(char expr) {
  if (isAtEnd()) return false;
  if (*scanner.current != expr) return false;
  scanner.current++;
  return true;
}
static char peak() { return *scanner.current; }
static void skipWhitespace() {
  for (;;) {
    char expr = peak();
    switch (expr) {
      case ' ':
      case '\r':
      case '\t':
        advance();
        break;
      case '\n':
        scanner.lines++;
        advance();
        break;
      default:
        return;
    }
  }
}
static Token giveToken(TokenType type) {
  // generates token
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
// Scans and tokenises using the give Token function
Token scanToken() {
  skipWhitespace();
  scanner.start = scanner.current;
  if (isAtEnd()) return giveToken(TOKEN_EOF);
  char c = advance();
  switch (c) {
    case '(':
      return giveToken(TOKEN_LEFT_PAREN);
    case ')':
      return giveToken(TOKEN_RIGHT_PAREN);
    case '{':
      return giveToken(TOKEN_LEFT_BRACE);
    case '}':
      return giveToken(TOKEN_RIGHT_BRACE);
    case ';':
      return giveToken(TOKEN_SEMICOLON);
    case ',':
      return giveToken(TOKEN_COMMA);
    case '.':
      return giveToken(TOKEN_DOT);
    case '-':
      return giveToken(TOKEN_MINUS);
    case '+':
      return giveToken(TOKEN_PLUS);
    case '/':
      return giveToken(TOKEN_SLASH);
    case '*':
      return giveToken(TOKEN_STAR);
    case '!':
      return giveToken(match('=') ? TOKEN_BANG_EQUAL : TOKEN_BANG);
    case '<':
      return giveToken(match('=') ? TOKEN_LESS_EQUAL : TOKEN_LESS);
    case '=':
      return giveToken(match('=') ? TOKEN_EQUAL_EQUAL : TOKEN_EQUAL);
    case '>':
      return giveToken(match('=') ? TOKEN_GREATER_EQUAL : TOKEN_GREATER);
  }
  return errorToken("Unexpected char .");
}
#endif
