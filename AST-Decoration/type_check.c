/* See chapter 7 - Resolver code */

/* Need the type, AST, symbol, scope, and printing libraries'
    constants, structures, and function prototypes */
#include "type_check.h"
#include "ast_library.h"
#include "symbol.h"
#include "scope.h"
#include "ast_printer.h"

/* Standard libraries used */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* Create a global counter for the number of semantic errors detected */
int count = 0;

/* typecheck_error_count() - returns the number of errors detected */
int typecheck_error_count(){
    return count;
}

/* decl_resolve() - handles scope management for declarations */
void decl_resolve(struct decl *decl){
    if(!decl){
        return;
    }
    symbol_t kind = scope_level() > 1 ?
                    SYMBOL_LOCAL : SYMBOL_GLOBAL;
    decl->symbol = symbol_create(kind, decl -> type, decl -> name);
    expr_resolve(decl->value);
    if (scope_lookup_current(decl -> name) && decl -> type -> kind != TYPE_FUNCTION) {
        count++;
    } else {
        scope_bind(decl->name, decl->symbol);
    }
    if (decl -> code) {
        scope_enter();
        param_list_resolve(decl -> type -> params);
        stmt_resolve(decl -> code);
        scope_exit();
    }
    decl_resolve(decl->next);
}
/* expr_resolve() - handles scope management for expressions */
void expr_resolve(struct expr *expr){
    if(!expr){
        return;
    }
    if (expr -> kind == EXPR_NAME) {
        if (scope_lookup(expr -> name) != NULL) {
            expr -> symbol = scope_lookup(expr -> name);
        } else {
            count++;
        }     
    } else {
        expr_resolve(expr -> left);
        expr_resolve(expr -> right);
    }
}
/* stmt_resolve() - handles scope management for statements */
void stmt_resolve(struct stmt *stmt){
    if (!stmt){
        return;
    }
    if (stmt -> kind == STMT_BLOCK || stmt->kind == STMT_FOR || stmt->kind == STMT_IF_ELSE) {
        scope_enter();
    }
    decl_resolve(stmt->decl);
    expr_resolve(stmt->init_expr);
    expr_resolve(stmt->expr);
    expr_resolve(stmt->next_expr);
    stmt_resolve(stmt->body);
    stmt_resolve(stmt->else_body);

    if (stmt->kind == STMT_BLOCK || stmt->kind == STMT_FOR || stmt->kind == STMT_IF_ELSE) {
        scope_exit();
    }
    stmt_resolve(stmt->next);
}

/* param_list_resolve() */
void param_list_resolve(struct param_list *param_list) {
    if (!param_list) return;
    if (scope_lookup_current(param_list -> name)) {
        count++;
    } else {
        param_list -> symbol = symbol_create(SYMBOL_PARAM, param_list -> type, strdup(param_list -> name));
        scope_bind(param_list -> name, param_list -> symbol);
    }
    param_list_resolve(param_list -> next);
}
