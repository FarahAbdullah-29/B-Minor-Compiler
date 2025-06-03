/* See chapter 7 - Resolver code */

/* Include type_check.h, ast_library.h, symbol.h, scope.h, and ast_printer.h */
#include "type_check.h"
#include "ast_library.h"
#include "symbol.h"
#include "scope.h"
#include "ast_printer.h"

/* Include <stdio.h>, <stdlib.h>, and <stdarg.h> */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Counter for number of errors detected */
int _typecheck_error_count = 0;

// Used for setting "which" for parameters and local variables
int _variable_count = 0;

/* typecheck_error_count() - returns the number of errors detected */
int typecheck_error_count() {
    return _typecheck_error_count;
}

/* report_error() - displays a message on the console. Works like printf() and
                  adds one to the error count */
void report_error(char *format, ...) {
    char *traverse = format;
    va_list args;
    va_start(args, format);
    printf("TYPECHECK ERROR: ");
    while (*traverse != '\0') {
     if (*traverse == '%') {
       ++traverse;
       if (*traverse == '\0') {
         printf("\nFORMAT ERROR: format string [%s] ends with %%\n", format);
         return;
       } else if (*traverse == 's') {
         char *s = va_arg(args, char *);
         printf("%s", s);
       } else if (*traverse == 'd') {
         int i = va_arg(args, int);
         printf("%d", i);
       } else if (*traverse == 'c') {
         int c = va_arg(args, int);
         printf("%c", c);
       } else if (*traverse == 'f') {
         double d = va_arg(args, double);
         printf("%f", d);
       }
     } else {
       printf("%c", *traverse);
     }

     ++traverse;
    }

    va_end(args);

    ++_typecheck_error_count;
}


/* Chapter 7 RESOLVER CODE */

/* decl_resolve() - handles scope management for declarations */

void decl_resolve(struct decl *d) {
    if (!d) {
        return;
    }

    if (d->type->kind == TYPE_ARRAY) {
      printf("Typecheck decl resolve for %s (%s of %s)\n", d->name, getTypeName(d->type->kind), getTypeName(d->type->subtype->kind));
    } else {
      printf("Typecheck decl resolve for %s (%s)\n", d->name, getTypeName(d->type->kind));
    }

    symbol_t kind = scope_level() > 1? SYMBOL_LOCAL : SYMBOL_GLOBAL;

    // Check for redeclaration of identifier in same scope
    if (scope_lookup_current(d->name)) {
        // Deal with function prototype versus definition
        if (scope_lookup_current(d->name)->type->kind == TYPE_FUNCTION && d->type->kind == TYPE_FUNCTION) {
            if (d->type->subtype->kind != scope_lookup(d->name)->type->subtype->kind) {
                report_error("Function type differs in redefinition for %s\n", d->name);
            }
        } else {
            // Redeclaration of variable in same scope
            report_error("Redeclaration of variable %s\n", d->name);
        }
    }

    d->symbol = symbol_create(kind, d->type, d->name);

    expr_resolve(d->value);
    scope_bind(d->name, d->symbol);

    // for local variables, set value for "which" representing the variable's
    // ordinal position of declaration in the function - used when generating
    // ASM code later
    if (scope_level() > 1) {
      if (d->type->kind == TYPE_ARRAY || d->type->kind == TYPE_STRING || d->type->kind == TYPE_INTEGER || d->type->kind == TYPE_BOOLEAN || d->type->kind == TYPE_CHARACTER) {
        ++_variable_count;
        scope_lookup(d->name)->which = _variable_count;
      }
    }

    if (d->code) {
      scope_enter();

      // Set variable count for this block back to 0
      _variable_count = 0;

      param_list_resolve(d->type->params);
      stmt_resolve(d->code->body);

      scope_exit();
    }

    decl_resolve(d->next);
}

/* expr_resolve() - handles scope management for expressions */
void expr_resolve(struct expr *e) {
    if (!e) {
      return;
    }

    if (e->kind == EXPR_NAME) {
      // This modifies the AST entry to associate the symbol with the name (variable)
      e->symbol = scope_lookup(e->name);
      if (!e->symbol) {
          report_error("Undeclared identifier %s\n", e->name);
      }
    }

    expr_resolve(e->left);
    expr_resolve(e->right);
}

/* param_list_resolve() - handles scope management for parameter lists */
void param_list_resolve(struct param_list *p) {
    if (!p) {
      return;
    }

    // Add to symbol table and set the
    // value for "which", indicating the parameters ordinal position in the
    // list which will be needed when generating the ASM code later.
    scope_bind(p->name, symbol_create(SYMBOL_PARAM, p->type, p->name));
    ++_variable_count;
    scope_lookup(p->name)->which = _variable_count;

    param_list_resolve(p->next);
}

/* stmt_resolve() - handles scope management for statements */
void stmt_resolve(struct stmt *s) {
    if (!s) {
      return;
    }

    // Assume same scope
    int separate_scope = 0;

    // New scope needed: block, for, if
    if (s->kind == STMT_BLOCK || s->kind == STMT_FOR || s->kind == STMT_IF_ELSE) {
      separate_scope = 1;
      scope_enter();
    }

    decl_resolve(s->decl);
    expr_resolve(s->init_expr);
    expr_resolve(s->expr);
    expr_resolve(s->next_expr);
    stmt_resolve(s->body);
    stmt_resolve(s->else_body);

    if (separate_scope) {
      scope_exit();
    }

    stmt_resolve(s->next);
}

/* Chapter 7 TYPE CHECKER CODE */

/* type_equals() - checks if two types are the same and returns
                true (1) if they are. For arrays and function
                types, the check involves checking all the
                subtypes recursively for equivalence. */
int type_equals(struct type *a, struct type *b) {
    // TODO Implement the function
    return 0;
}

/* type_copy() - makes a duplicate of a type. */
struct type *type_copy(struct type *t) {
    // TODO Implement the function
    if (!t) {
      return 0;
    }

    struct type *tcopy = 0;

    return tcopy;
}

/* param_list_copy() - makes a duplicate of a param_list. */
struct param_list *param_list_copy(struct param_list *p) {
    // TODO Implement the function
    if (!p) {
      return 0;
    }

    struct param_list *paramscopy = 0;

    return paramscopy;
}

/* type_delete - frees the memory for a type. */
void type_delete(struct type *t) {
    // TODO Implement the function
    if (!t) {
      return;
    }
}

/* param_list_delete() - frees the memory for a param_list */
void param_list_delete(struct param_list *p) {
    // TODO Implement the function
    if (!p) {
      return;
    }
}

/* expr_typecheck() - checks type agreement for expressions */
struct type *expr_typecheck(struct expr *e) {
    if (!e) {
      return 0;
    }

    struct type *lt = expr_typecheck(e->left);
    struct type *rt = expr_typecheck(e->right);

    struct type *result = 0;

    printf("DEBUG: Check expression type %d (%s)\n", e->kind, getExprName(e->kind));

    switch (e->kind) {
      case EXPR_INTEGER_LITERAL:
        result = type_create(TYPE_INTEGER, 0, 0);
        break;
      case EXPR_STRING_LITERAL:
        result = type_create(TYPE_STRING, 0, 0);
        break;

      // TODO ADD ADDITIONAL CASES

      default:
        printf("TYPECHECK WARNING: IGNORED EXPR TYPE: %d (%s)\n", e->kind, getExprName(e->kind));
        result = type_create(TYPE_VOID, 0, 0);

    }

    type_delete(lt);
    type_delete(rt);

    return result;
}

/* Pointer to the current function's declaration */
struct decl *_current_function_decl = 0;

/* decl_typecheck() - checks that initialization types agree */
void decl_typecheck(struct decl *d) {
    if (!d) {
      return;
    }

    if (d->value) {
      printf("DEBUG: Check decl type for %s\n", d->name);
      struct type *t;
      t = expr_typecheck(d->value);
      if (d->type->kind != TYPE_ARRAY && !type_equals(t, d->symbol->type)) {
        report_error("Initialization type mismatch (non-array)\n");
      } else if (d->type->kind == TYPE_ARRAY && !type_equals(t, d->symbol->type->subtype)) {
        report_error("Initialization type mismatch (array)\n");
      }
    }

    // If this is a function declaration, track it
    // as the current function
    if (d->type->kind == TYPE_FUNCTION) {
      _current_function_decl = d;
    }

    stmt_typecheck(d->code);
    decl_typecheck(d->next);
}

/* stmt_typecheck() - call appropriate type checks based on statement type */
void stmt_typecheck(struct stmt *s) {
    if (!s) {
      return;
    }

    struct type *t;
    printf("DEBUG: stmt type check for %d (%s)\n", s->kind, getStmtName(s->kind));
    switch (s->kind) {
      case STMT_EXPR:
        t = expr_typecheck(s->expr);
        type_delete(t);
        break;
      case STMT_IF_ELSE:
        t = expr_typecheck(s->expr);
        if (t->kind != TYPE_BOOLEAN) {
          report_error("if condition must be a boolean\n");
        }
        type_delete(t);
        stmt_typecheck(s->body);
        stmt_typecheck(s->else_body);
        break;

      // TODO ADD ADDITIONAL CASES

      default:
        printf("TYPECHECK WARNING: IGNORED STMT TYPE: %d (%s)\n", s->kind, getStmtName(s->kind));
    }

    stmt_typecheck(s->next);
}
