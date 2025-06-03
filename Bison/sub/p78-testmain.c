#include <stdio.h>
#include "expr.h"
extern int yyparse();

extern struct expr* parser_result;


int main() {
if (yyparse() == 0) {
    printf("Parse successful\n");
    printf("Expression from AST: ");
    expr_print(parser_result);
    printf("\nResult is %d\n", expr_evaluate(parser_result));
  } else {
    printf("Parse failed\n");
  }
}
