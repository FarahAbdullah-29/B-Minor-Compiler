// Test code for the interpreter-based grammar definition
// Page 75

#include <stdio.h>

extern int yyparse();

extern int parser_result;

int main() {
  if (yyparse() == 0) {
    printf("Parse successful\n");
    printf("Result is %d\n", parser_result);
  } else {
    printf("Parse failed\n");
  }
}
