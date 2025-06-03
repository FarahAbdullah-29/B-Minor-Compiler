/*
 Header file for the library of AST printing functions.
*/

#ifndef AST_PRINTER_H

// Comment out the NOTREADY define once
// you have created all the types and
// structures required for statements,
// expressions, and parameters in
// ast_library.h
//#define NOTREADY

#define AST_PRINTER_H

#include "ast_library.h"

// Recursive functions for printing the AST
void decl_print(struct decl *node);
void type_print(struct type *node);

#ifndef NOTREADY
void expr_print(char *prefix, struct expr *node);
void stmt_print(char *prefix, struct stmt *node);
void param_list_print(struct param_list *node);

// Lookup functions for getting type constant names
char *getExprName(expr_t kind);
char *getStmtName(stmt_t kind);
#endif // NOTREADY

char *getTypeName(type_t value);

// Specialised output for managing indentation
void indent(int do_print, int adjust_spaces);
void iprintf(char* format, ...);

#endif // AST_PRINTER_H
