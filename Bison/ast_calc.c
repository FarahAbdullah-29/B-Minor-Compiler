/* routines for AST calculator */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast_calc.h"
#include "ast_calc.tab.h"

/* Create a new AST node */
struct ast *newast(int nodetype, struct ast *l, struct ast *r) {
  struct ast *a = (struct ast *) malloc(sizeof(struct ast)); // need to malloc structure 1st

  if (!a) {
    yyerror("out of space");
    exit(0);
  } // check for memory #2

  // Assign parameters into structure members #3
  a->nodetype = nodetype;
  a-> left = l;
  a-> right = r;

  return a;
}

/* Create a new numeric value node,
    cast to an AST node */
struct ast *newnum(double d) {
  struct numval *a = (struct numval *) malloc(sizeof(struct numval)); // need to malloc structure

  if (!a) {
    yyerror("out of space");
    exit(0);
  }

  a->nodetype = TOKEN_NUMBER;
  a->number = d;

  // Assign parameters into structure members
  // Use the number token as the node type for numbers

  return (struct ast *)a;
}

/* Evaluate the AST subtree that is given */
double eval(struct ast *a) {
  double v; // calculated value of this subtree

  // Process each node type, recursing as necessary to
  // evaluate subtrees
  switch(a->nodetype) {
    case TOKEN_NUMBER: v = ((struct numval *) a)->number;
    break;
    case TOKEN_ADD: v= eval(a->left) + eval(a->right);
    break;
    case TOKEN_SUB: v= eval(a->left) - eval(a->right);
    break;
    case TOKEN_MULT: v= eval(a->left) * eval(a->right);
    break;
    case TOKEN_DIV: v= eval(a->left) / eval(a->right);
    break;
    case TOKEN_ABS: v = eval(a->left); if(v < 0) v = -v;
    break;
    default: printf("Internal error: bad node %d\n", a->nodetype);
        v = 0;
  }

  return v;
}

/* Clean up allocated memory from the AST */
void treefree(struct ast *a) {
  // Some nodetypes have two children (left and
  // right), others only have one (left), and
  // numbers have no subtrees.
  // Remember to free the subtrees before
  // freeing the current node

  switch(a->nodetype) {
    case TOKEN_ADD: 
    case TOKEN_SUB:
    case TOKEN_MULT:
    case TOKEN_DIV:
      treefree(a->right);
      treefree(a->left);
      free(a);
      break;
    case TOKEN_ABS:
      treefree(a->left);
      free(a);
      break;
    case TOKEN_NUMBER:
      free(a);
      break;



    default: printf("internal error: bad free node %d\n", a->nodetype);
  }
}

/* Called by our scanner and Bison's generated code
    when a lexing or parsing error occurs */
void yyerror(char *s, ...) {
  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

/* Run the parser */
int main() {
  printf("> ");
  return yyparse();
}
