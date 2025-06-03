/* See chapter 7 - Symbol management code */

#ifndef SYMBOL_H

#define SYMBOL_H

/* Typedef for symbol enum */
typedef enum {
    SYMBOL_LOCAL,
    SYMBOL_PARAM,
    SYMBOL_GLOBAL
} symbol_t;

/* Structure declaration for symbol */
struct symbol {
    symbol_t kind;
    struct type *type;
    const char *name;
    int which;
};

/* Prototype for the symbol_create function */
struct symbol *symbol_create(symbol_t kind, struct type *type, const char *name);

#endif // SYMBOL_H
