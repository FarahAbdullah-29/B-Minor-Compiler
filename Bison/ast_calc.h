/*
 * Declarations for the AST calculator
 */

/* interface to the lexer */
extern int yylineno; // from lexer
void yyerror(char *s, ...);

/* Nodes in the abstract syntax tree (AST) */

// The calculator AST is a binary tree.
// The ast type has an integer nodetype member
// and left and right subtrees (ast structures)
struct ast {
    int nodetype;
    struct ast *left;
    struct ast *right; // represents a node
};

// The numval structure represents a value.
// It contains an integer nodetype member
// and a double number member.
struct numval {
    int nodetype;
    double number;
};

/* Function prototypes for creating the nodes */
struct ast *newast(int nodetype, struct ast *l, struct ast *r);
struct ast *newnum(double d);

/* Function prototype for evaluating the AST */
double eval(struct ast *);

/* Function prototype for freeing an AST's memory */
void treefree(struct ast *);
