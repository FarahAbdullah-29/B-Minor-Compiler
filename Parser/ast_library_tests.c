#include <stdio.h>
#include "ast_library.h"
#include "ast_printer.h"

/* Test the ast_library factory functions */

// Prototype for function to append a decl to a decl list
struct decl *append(struct decl *node, struct decl *new_node);

// Create a small AST directly
int main() {
    struct decl *root = NULL;
    struct decl *decl = NULL;
    struct type *type = NULL;
    struct type *sub_type = NULL;
    struct expr *expr = NULL;
    struct stmt *stmt = NULL;
    struct param_list *params = NULL;

    // First decl: int global x, w/o initialization
    type = type_create(TYPE_INTEGER, NULL, NULL);
    root = append(root, decl_create("x", type, NULL, NULL, NULL));

    // Second decl: boolean global y, w/inititialization -> true (1)
    type = type_create(TYPE_BOOLEAN, NULL, NULL);
    expr = expr_create_boolean_literal(1);
    root = append(root, decl_create("y", type, expr, NULL, NULL));

    // Third decl: global function, func_z,
    //              returning char, w/o parameter
    // Function contains one statement, a string declaration
    //              for local variable a
    type = type_create(TYPE_STRING, NULL, NULL);
    decl = decl_create("a", type, NULL, NULL, NULL);
    stmt = stmt_create(STMT_DECL, decl, NULL, NULL, NULL, NULL, NULL, NULL);
    sub_type = type_create(TYPE_CHARACTER, NULL, NULL);
    type = type_create(TYPE_FUNCTION, sub_type, NULL);
    root = append(root, decl_create("func_z", type, NULL, stmt, NULL));

    // Fourth decl: global function func_b, returning void,
    //              w/integer parameter param_c, and,
    //              string parameter param_d
    // Function contains one statement,
    //              a char declaration for variable e,
    //              initialized to 'F'
    type = type_create(TYPE_CHARACTER, NULL, NULL);
    expr = expr_create_char_literal('F');
    decl = decl_create("e", type, expr, NULL, NULL);
    stmt = stmt_create(STMT_DECL, decl, NULL, NULL, NULL, NULL, NULL, NULL);
    type = type_create(TYPE_STRING, NULL, NULL);
    params = param_list_create("param_d", type, NULL);
    type = type_create(TYPE_INTEGER, NULL, NULL);
    params = param_list_create("param_c", type, params);
    sub_type = type_create(TYPE_VOID, NULL, NULL);
    type = type_create(TYPE_FUNCTION, sub_type, params);
    root = append(root, decl_create("func_b", type, NULL, stmt, NULL));

    // Print the tree
    decl_print(root);

    return 0;
}

/* Append a decl to the end of a decl list */
struct decl *append(struct decl *node, struct decl *new_node) {
    if (!node) {
        return new_node;
    } else if (!node->next) {
        node->next = new_node;
        return node;
    }

    return node->next = append(node->next, new_node);
}
