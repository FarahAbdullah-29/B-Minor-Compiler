#include "scope.h"
#include "hash_table.h"
#include "ast_library.h"
#include <stdio.h>
#include <stdlib.h>

/* Variable to hold pointer to top of stack */
struct scope_stack_element *scope_top = NULL;
/* scope_enter() - creates a new stack element with a new hashtable
                and places the new scope at the top of the stack */
void scope_enter(){
    struct scope_stack_element *scope = malloc(sizeof(scope));
    if(!scope){
        yyerror("Out of Space");
        exit(0);
    };
    scope->ht = hash_table_create(0,0);
    if (!scope -> ht){
        yyerror("Hashtable not created scope not in hash");
        free(scope);
        exit(0);
    }
    scope -> previous_element = scope_top;
    scope_top = scope;
}
/* scope_exit() - If the stack is not empty, free the top stack element
                and hashtable, make the previous scope, if there is one,
                the top of the stack */
void scope_exit(){
    if(scope_top != NULL){
        hash_table_delete(scope_top -> ht);
        struct scope_stack_element *previous_element = scope_top -> previous_element;
        free(scope_top);
    }else{
        yyerror("Hash table stack is empty");
        exit(0);
    }
}
/* scope_level() - returns the depth of the stack */
int scope_level(){
    int level = - 1;
    struct scope_stack_element *current_scope = malloc(sizeof(current_scope));
    current_scope = scope_top;

    while(current_scope != NULL){
        current_scope = current_scope -> previous_element;
        level++;
    }
    return level;
}
/* scope_bind() - adds the name and symbol to the current scope's hashtable */
void scope_bind(const char *name, struct symbol *sym){
    if(scope_top == NULL){
        yyerror("Scope not found");
        return;
    }else{
        int hash_value = hash_table_insert(scope_top ->ht, name, sym);
        if(hash_value == 0 && sym ->type->kind != TYPE_FUNCTION){
            yyerror("Symbol already exists in scope");
        }
    }
}
/* scope_lookup() - locates the name in the stack, beginning at the top.
                  Returns the associated symbol, or NULL if not found */
struct symbol *scope_lookup(const char *name){
    struct scope_stack_element *current_scope = malloc(sizeof(current_scope));
    current_scope = scope_top;

    while(current_scope != NULL){
        struct symbol *sym = hash_table_lookup(current_scope ->ht, name);
        if(sym != NULL){
            return sym;
        }
        current_scope = current_scope -> previous_element;
    }
    printf("Error, %s is undelcared: ", name);
    return NULL;
}
/* scope_lookup_current() - locates the name in the current scope,
                          the top element of the stack.
                          Returns the associated symbol, or NULL if not found */
struct symbol *scope_lookup_current(const char*name){
    if(scope_top == NULL){
        yyerror("No Scope");
        return NULL;
    }
    struct symbol *sym = hash_table_lookup(scope_top ->ht, name);
    if(sym != NULL && sym ->type->kind != TYPE_FUNCTION){
        printf("ERROR, redeclared of %s: ", name);
    }
    return sym;
}