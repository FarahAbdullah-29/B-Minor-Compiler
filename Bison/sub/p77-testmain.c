// Test code for the hand-created AST example
// Page 77

#include <stdio.h>
#include "expr.h"

int main() {
  struct expr* a = expr_create_value(10);
  struct expr* b = expr_create_value(20);
  struct expr* c = expr_create(EXPR_ADD, a, b);
  struct expr* d = expr_create_value(30);
  struct expr* e = expr_create(EXPR_MULTIPLY, c, d);
  printf("Expression from AST: ");
  printf("\nResult is %d\n", expr_evaluate(e));
  expr_print(e);
}
