/* See chapter 7 - Symbol management code */

/* Need symbol and AST constants and structures */
#include "symbol.h"
#include "ast_library.h"
#include <stdlib.h>

/* symbol_create - create a copy of  struct symbol and populate its members from
                  the function's parameters */
struct symbol * symbol_create(symbol_t kind, struct type *type, char *name){
    struct symbol *s = malloc(sizeof(*s));
    s->kind = kind;
    s->type = type;
    s->name = name;
    return s;
    }