/* See chapter 7 - Scope management code */

#ifndef SCOPE_H

#define SCOPE_H

/* Include the hash_table.h and symbol.h files */
#include "hash_table.h"
#include "symbol.h"

/* The scope_stack_element struct holds a pointer to the hash table
 and previous stack node */
struct scope_stack_element {
    struct hash_table *table;
    struct scope_stack_element *prev;
};

/* Prototypes for scope management functions */
void scope_enter();
void scope_exit();
int scope_level();

void scope_bind(const char *name, struct symbol *sym);
struct symbol *scope_lookup(const char *name);
struct symbol *scope_lookup_current(const char *name);

#endif // SCOPE_H
