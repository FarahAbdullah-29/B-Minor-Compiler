// Test code for the validator example
// Page 72
#include <stdio.h>

extern int yyparse();

int main() {
  if (yyparse() == 0) {
    printf("Parse successful\n");
  } else {
    printf("Parse failed\n");
  }
}
