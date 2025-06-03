
#ifndef TYPE_CHECK_H

/* Need to access the AST structure definitions */
#include "ast_library.h"

#define TYPE_CHECK_H

/* Prototype for typecheck_error_count() */
int typecheck_error_count();

/* Resolver Function Prototypes */
void decl_resolve(struct decl *decl);
void expr_resolve(struct expr *expr);
void stmt_resolve(struct stmt *stmt);
void param_list_resolve(struct param_list *param_list);
#endif // TYPE_CHECK_H
