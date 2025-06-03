// Header file inclusion
#include "ast_library.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a declaration
struct decl * decl_create(char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next) {
  // Allocate memory for declaration
  struct decl *d = malloc(sizeof(*d));

  // Check memory allocation
  if (!d) {
    yyerror("out of space: declaration");
    exit(0);
  }

  // Set member variables
  d->name = name;
  d->type = type;
  d->value = value;
  d->code = code;
  d->next = next;

  // Return the structure pointer
  return d;
};

// Function to create a statement
struct stmt *stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr,
  struct expr *expr, struct expr *next_expr,
  struct stmt *body, struct stmt *else_body,
  struct stmt *next){

    // Allocate memory for statement
    struct stmt *s = malloc(sizeof(*s));
    // Check memory allocation
    if (!s) {
      yyerror("out of space: declaration");
      exit(0);
    }

    // Set member variables
    s->kind=kind;
    s->decl = decl;
    s->init_expr = init_expr;
    s->expr = expr;
    s->next_expr = next_expr;
    s->body = body;
    s->else_body = else_body;
    s->next = next;

    // Return the structure pointer
    return s;
}

// Function to create an expression
struct expr *expr_create(expr_t kind, struct expr * left, struct expr * right){
  // Allocate memory for expression
  struct expr *e = malloc(sizeof(*e));

  // Check memory allocation
  if (!e) {
    yyerror("out of space: declaration");
    exit(0);
  }

  // Set member variables
  e->kind = kind;
  e->left = left;
  e->right = right;
  e->name = NULL;
  e->integer_value = 0;
  e->string_literal = NULL;
  
  // Return the structure pointer
  return e;
}

// Function to create a variable (name) expression
struct expr *expr_create_name(const char *name){
  // Create an expression
  struct expr *n= expr_create(EXPR_NAME,NULL,NULL);
  
  // Set name
  n->name = name;
  
  // Return the structure pointer
  return n;
}

// Function to create an integer literal expression
struct expr *expr_create_integer_literal(int i){
  // Create an expression
  struct expr *il = expr_create(EXPR_INTEGER_LITERAL,NULL,NULL);
  
  // Set integer value
  il->integer_value = i;
  
  // Return the structure pointer
  return il;
}

// Function to create a Boolean literal expression
struct expr *expr_create_boolean_literal(int i){
  // Create an expression
  struct expr *bl = expr_create(EXPR_BOOLEAN_LITERAL,NULL,NULL);
  
  // Set integer value
  bl->integer_value = i;
  
  // Return the structure pointer
  return bl;
}

// Function to create a character literal expression
struct expr *expr_create_char_literal(char c){
  // Create an expression
  struct expr *cl = expr_create(EXPR_CHAR_LITERAL,NULL,NULL);
  
  // Set integer value
  cl->integer_value = c;
  
  // Return the structure pointer
  return cl;
}

// Function to create a string literal expression
struct expr *expr_create_string_literal( const char *str){
  // Create an expression
  struct expr *sl= expr_create(EXPR_STRING_LITERAL,NULL,NULL);
  
  // Set string literal
  sl->string_literal = str;
  
  // Return the structure pointer
  return sl;
}

// Function to create a type
struct type *type_create(type_t kind, struct type *subtype, struct param_list *params) {
  // Allocate memory for type
  struct type *t = malloc(sizeof(*t));

  // Check memory allocation
  if (!t) {
    yyerror("out of space: type");
    exit(0);
  }

  // Set member variables
  t->kind = kind;
  t->subtype = subtype;
  t->params = params;

  // Return the structure pointer
  return t;
}

// Function to create a parameter
struct param_list *param_list_create(char *name, struct type *type, struct param_list *next){
  // Allocate memory for parameter list
  struct param_list *pl = malloc(sizeof(*pl));

  // Check memory allocation
  if (!pl) {
    yyerror("out of space: declaration");
    exit(0);
  }

  // Set member variables
  pl->name = name;
  pl->type= type;
  pl->next= next;
  
  // Return the structure pointer
  return pl;
}
