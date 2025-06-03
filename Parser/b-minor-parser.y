%{
#include "ast_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The result of parsing (root of tree)
    starts with a declaration node.
    A B-Minor program is represented
    as a list of declarations. */
struct decl * parser_result = 0;

/* Error reporting function */
extern void yyerror(const char *);

/* Lexing function and lexeme from
    Flex-generated scanner */
extern int yylex();
extern char *yytext;
%}

%token TOKEN_ARRAY;
%token TOKEN_BOOLEAN;
%token TOKEN_CHAR;
%token TOKEN_ELSE;
%token TOKEN_FALSE;
%token TOKEN_FOR;
%token TOKEN_FUNCTION;
%token TOKEN_IF;
%token TOKEN_INTEGER;
%token TOKEN_PRINT;
%token TOKEN_RETURN;
%token TOKEN_STRING;
%token TOKEN_TRUE;
%token TOKEN_VOID;
%token TOKEN_WHILE;
%token TOKEN_LITERAL_INT;
%token TOKEN_LITERAL_CHAR;
%token TOKEN_LITERAL_STRING;
%token TOKEN_IDENT;
%token TOKEN_POSTFIX_ADD;
%token TOKEN_POSTFIX_MINUS;
%token TOKEN_GREATER_EQUAL;
%token TOKEN_LESS_EQUAL;
%token TOKEN_EQUAL;
%token TOKEN_NOT_EQUAL;
%token TOKEN_NOT;
%token TOKEN_LOGICAL_AND;
%token TOKEN_LOGICAL_OR;
%token TOKEN_LPAREN;
%token TOKEN_RPAREN;
%token TOKEN_LBRACKET;
%token TOKEN_RBRACKET;
%token TOKEN_LBRACE;
%token TOKEN_RBRACE;
%token TOKEN_EXPONENTIATION;
%token TOKEN_MUL;
%token TOKEN_DIV;
%token TOKEN_MOD;
%token TOKEN_PLUS;
%token TOKEN_MINUS;
%token TOKEN_COMMA;
%token TOKEN_GREATER;
%token TOKEN_LESS;
%token TOKEN_ASSIGN;
%token TOKEN_COLON;
%token TOKEN_SEMI;
%token TOKEN_ERROR;

%define parse.trace

%nonassoc NO_ELSE
%nonassoc TOKEN_ELSE

%union {
  struct decl *decl;
  struct stmt *stmt;
  struct expr *expr;
  struct type *type;
  struct param_list *param_list;
  char *name;
  int value;
};

%type <decl> program globals global var_decl function_decl;
%type <stmt> stmts stmt stmt_block function_def if_stmt for_stmt print_stmt return_stmt;
%type <expr> expr pm_expr lo_expr term expon factor assignment postfix opt_assignment opt_expr opt_increment literal args arg_list arg function_call array_init val_list array_element not;
%type <type> atomic_type return_type;
%type <param_list> params param_list param;
%type <name> identifier TOKEN_IDENT;
%type <value> relational_op length logical_op;
%%

/* A program is a set of global declarations */
program: globals         { parser_result = $1; printf(">=================>program: globals\n"); }
      ;

/* Globals are 0 or more global declarations */
globals: global globals    { $$ = $1; $1->next = $2; printf(">=================>globals: global\n");}
      | /* epsilon */     { $$ = 0; printf(">=================>globals: epsilon\n"); }
      ;

/* A global is a variable or function declaration */
global: var_decl TOKEN_SEMI     { $$ = $1; printf(">=================>global: var_decl\n");}
      | function_decl       { $$ = $1; printf(">=================>global: function decl\n"); }
      ;

/* A variable declaration is for a scalar or array and is either uninitialized or initialized */
var_decl: identifier TOKEN_COLON atomic_type         { $$ = decl_create($1, $3, 0, 0, 0); printf(">==t10===============>var_decl: declaration only %s\n", $1); }
        | identifier TOKEN_COLON atomic_type TOKEN_ASSIGN expr  { $$ = decl_create($1, $3, $5, 0, 0); printf(">==t11===============>var_decl: declare and initialize %s\n", $1); }
        | identifier TOKEN_COLON TOKEN_ARRAY TOKEN_LBRACKET length TOKEN_RBRACKET atomic_type  { $$ = decl_create($1, $7, 0, 0, 0); printf(">==t12===============>var_decl: declare array %s [%d]\n", $1, $5); }
        | identifier TOKEN_COLON TOKEN_ARRAY TOKEN_LBRACKET length TOKEN_RBRACKET atomic_type TOKEN_ASSIGN array_init  { $$ = decl_create($1, $7, $9, 0, 0); printf(">==t14===============>var_decl: declare and initialize array %s [%d] \n", $1, $5); }
        ;

/* A length is a literal int token */
length: TOKEN_LITERAL_INT  { $$ = atoi(yytext); printf(">=================>length: %d\n", $$); }
      ;

/* An array initialization is a value list contained withing brace tokens */
array_init: TOKEN_LBRACE val_list TOKEN_RBRACE  { $$ = $2; printf(">==t===============>array inititialization\n"); }
          ;

/* A value list is one or more literal values separated by comma tokens */
val_list: literal  { $$ = $1;printf(">==t13===============>value for list\n"); }
        | literal TOKEN_COMMA val_list { $$ = $1; $1->left = $3; printf(">==t11===============>value list addition\n"); }
        ;

/* A function declaration is an identifier, colon token, function token, return type, parameters within parenthesis tokens and an optional function definition */
function_decl: identifier TOKEN_COLON TOKEN_FUNCTION return_type TOKEN_LPAREN params TOKEN_RPAREN TOKEN_SEMI { $$ = decl_create($1,type_create(TYPE_FUNCTION,$4,$6),0,0,0); printf(">==tf===============>function decl\n"); }
            | identifier TOKEN_COLON TOKEN_FUNCTION return_type TOKEN_LPAREN params TOKEN_RPAREN TOKEN_ASSIGN function_def { $$ = decl_create($1,type_create(TYPE_FUNCTION,$4,$6),0,$9,0); printf(">==tfn===============>function decl and def\n"); }
            ;

/* A function definition is a statement block */
function_def: stmt_block { $$ = $1; printf(">==t17===============>function def\n"); }
            ;

/* Parameters are empty or a parameter list */
params: param_list  { $$ = $1; printf(">==t14===============>params\n"); }
      | /* epsilon */ { $$ = 0; printf(">==t15===============>params: epsilon\n"); }
      ;

/* A parameter list is 1 or more parameters separated by comma tokens */
param_list: param { $$ = $1; printf(">==t3===============>param_list: param\n"); }
          | param TOKEN_COMMA param_list { $$ = $1; $1->next = $3; printf(">==t4===============>param_list: multiple params\n"); }
          ;

/* A parameter is an identifier followed by a colon token. Scalar types include a type, arrays include the array token, bracket tokens and the type */
param: identifier TOKEN_COLON atomic_type { $$ = $$ = param_list_create($1,$3,0); printf(">==y10===============>param %s\n", $1); }
    | identifier TOKEN_COLON TOKEN_ARRAY TOKEN_LBRACKET TOKEN_RBRACKET atomic_type  { $$ = param_list_create($1,$6,0); printf(">==UNSUPPORTED_FEATURE===============>param (array): %s\n", $1); }
    ;

/* Statements are 1 or more statements */
stmts: stmt { $$ = $1; printf(">==t16===============>stmt in stmts\n"); }
    | stmt stmts { $$ = $1; $1->next= $2; printf(">==t18===============>multiple stmts\n"); }
    ;

/* A statement can be a function call, variable declaration, assignment, postfix op, print, if, for, block, or return */
stmt: function_call TOKEN_SEMI { $$ = stmt_create(STMT_EXPR,0,0,$1,0,0,0,0); printf(">==t15===============>stmt: function call\n"); }
    | var_decl TOKEN_SEMI { $$ = stmt_create(STMT_DECL,$1,0,0,0,0,0,0); printf(">==t12===============>stmt: variable declaration\n"); }
    | assignment TOKEN_SEMI { $$ = stmt_create(STMT_EXPR,0,0,$1,0,0,0,0); printf(">==tt===============>stmt: assignment\n"); }
    | postfix TOKEN_SEMI { $$ = stmt_create(0,0,0,$1,0,0,0,0); printf(">==t12==============>stmt: postfix\n"); }
    | print_stmt TOKEN_SEMI { $$ = $1; printf(">==t24===============>print statement\n"); }
    | if_stmt { $$ = $1; printf(">==iff===============>stmt: if matched\n"); }
    | for_stmt { $$ = $1; printf(">==forr===============>stmt: for\n"); }
    | stmt_block { $$ = stmt_create(STMT_BLOCK,0,0,0,0,$1,0,0); printf(">==t11===============>stmt: block\n"); }
    | return_stmt TOKEN_SEMI { $$ = $1; printf(">==t19===============>stmt: return\n"); }
    ;

/* A statement block is a set of statements in brace tokens or an empty pair of brace tokens */
stmt_block: TOKEN_LBRACE stmts TOKEN_RBRACE { $$ = $2; printf(">==t20===============>statement block\n"); }
          | TOKEN_LBRACE TOKEN_RBRACE { printf(">==empty_block===============>empty statement block\n"); }
          ;

 /* A function call is an identifier and arguments inside of parentheses tokens */
function_call: identifier TOKEN_LPAREN args TOKEN_RPAREN { $$ = expr_create(EXPR_FUNCTIONCALL,expr_create_name($1),$3); printf(">==t13===============>function call %s\n", $1); }
            ;

/* Arguments are empty or an argument list */
args: arg_list { $$ = $1; printf(">==t10===============>args: argument list\n"); }
    | /* epsilon */     { $$ = 0; printf(">==t11===============>args: epsilon\n"); }
    ;

/* An argument list is 1 of more arguments separated by comma tokens */
arg_list: arg { $$ = $1; printf(">==t12===============>arg_list: arg\n"); }
        | arg TOKEN_COMMA arg_list { $$ = $1; $1->left = $3; printf(">==t13===============>arg_list: list of args\n"); }
        ;

/* An argument is an expression */
arg: expr  { $$ = $1; printf(">==t17===============>arg: expr\n"); }
  ;

/* An assignment is an identifier of a scalar or array, assignment token, and expression */
assignment: identifier TOKEN_ASSIGN expr { $$ = expr_create(EXPR_ASSIGN,expr_create_name($1),$3); printf(">==t13===============>assignment: non-array\n"); }
          |  array_element TOKEN_ASSIGN expr { $$ = expr_create(EXPR_ASSIGN,$1,$3); printf(">==t15===============>assignment: array element\n"); }
          ;

/* An identifier is a lexeme */
identifier: TOKEN_IDENT { $$ = strdup(yytext); printf(">=================>identifier %s\n", yytext); }
          ;

/* An expression is an expression, logical op, and logical expression or just a logical expression */
expr: expr logical_op lo_expr   { $$ = expr_create($2,$1,$3); printf(">==t19===============>expr: logical_op\n"); }
    | lo_expr { $$ = $1; printf(">==t20===============>expr: lo_expr\n"); }
    ;

/* A logical expression is a logical expression, relational op, and plus-minus operator or just plus-minus operator */
lo_expr: lo_expr relational_op pm_expr { $$ = expr_create($2,$1,$3); printf(">==t12===============>lo_expr: relational_op\n"); }
      | pm_expr { $$ = $1; printf(">==t15===============>lo_expr: pm_expr\n"); }
      ;

/* A plus-minus expression is a pm operator, plus or minus token, and a term or just a term */
pm_expr: pm_expr TOKEN_PLUS term      { $$ = expr_create(EXPR_ADD,$1,$3); printf(">==t+===============>pm_expr: addition\n"); }
      | pm_expr TOKEN_MINUS term     { $$ = expr_create(EXPR_SUB,$1,$3); printf(">==t-===============>pm_expr: subtraction\n");}
      | term { $$ = $1; printf(">==tt===============>pm_expr: term\n"); }
      ;

/* A term is a term followed by mult, div, or modulus token, followed by an exponent or just an exponent */
term: term TOKEN_MUL expon      { $$ = expr_create(EXPR_MUL,$1,$3); printf(">==tm===============>term: multiplication\n"); }
    | term TOKEN_DIV expon      { $$ = expr_create(EXPR_DIV,$1,$3); printf(">==td===============>term: division\n"); }
    | term TOKEN_MOD expon      { $$ = expr_create(EXPR_MODULUS,$1,$3); printf(">==t10===============>term: modulus\n"); }
    | expon { $$ = $1; printf(">==t11===============>term: expon\n"); }
    ;

/* An exponent is an exponent, exponentiation token, and a factor or just a factor */
expon: expon TOKEN_EXPONENTIATION factor { $$ = expr_create(EXPR_EXPONENTIATION,$1,$3); printf(">==t17===============>expon: exponentiation\n"); }
    | factor { $$ = $1; printf(">==t18===============>expon: factor\n");  }
    ;

/* A factor is a minus token followed by an expression, an expression in parentheses, identifier, literal, not token, array element, or function call */
factor: TOKEN_MINUS expr              { $$ = expr_create(EXPR_SUB,$2,0); printf(">==t20===============>factor: negate\n");}
      | TOKEN_LPAREN expr TOKEN_RPAREN  { $$ = $2; printf(">==t12===============>factor: parenthesized expression\n"); }
      | identifier { $$ = expr_create_name($1); printf(">==t16===============>factor: identifier\n"); }
      | literal { $$ = $1; printf(">==t18===============>factor: literal\n"); }
      | not { $$ = $1; printf(">==t15===============>factor: not\n");}
      | array_element { $$ = $1; printf(">==t11===============>factor: array element\n"); }
      | function_call { $$ = $1;printf(">==t10===============>factor: function call\n"); }
      ;

/* A not expression is a not token followed by an expression */
not: TOKEN_NOT expr { $$ = expr_create(EXPR_NOT,$2,0); printf(">==t13===============>not\n"); }
  ;

/* An array element is an identifier and an expression in brackets */
array_element: identifier TOKEN_LBRACKET expr TOKEN_RBRACKET { $$ = expr_create(EXPR_SUBSCRIPT,expr_create_name($1),$3); printf(">==t11===============>element of array %s\n", $1); }
            ;

/* An if statement is an if token, expression in parentheses, statement and optional else token with another statement */
/* No else has higher precedence (see %prec in first rule). An else clause will be associated with nearest if statement */
if_stmt: TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt %prec NO_ELSE { $$ = stmt_create(STMT_IF_ELSE,0,0,$3,0,$5,0,0); printf(">==t15===============>if without else\n"); }
      | TOKEN_IF TOKEN_LPAREN expr TOKEN_RPAREN stmt TOKEN_ELSE stmt { $$ = stmt_create(STMT_IF_ELSE,0,0,$3,0,$5,$7,0); printf(">==t18===============>if with else\n"); }
      ;

/* A for statement is a for token, optional assignment, optional expression, and optional increment in parentheses, followed by a statement */
for_stmt: TOKEN_FOR TOKEN_LPAREN opt_assignment TOKEN_SEMI opt_expr TOKEN_SEMI opt_increment TOKEN_RPAREN stmt { $$ = stmt_create(STMT_FOR,0,$3,$5,$7,$9,0,0);  printf(">==t20===============>for statement\n"); }
        ;

/* A return statement is a return token followed by an expression */
return_stmt: TOKEN_RETURN expr { $$ = stmt_create(STMT_RETURN,0,0,$2,0,0,0,0); printf(">==t11===============>return\n"); }
          ;

/* A print statement is a print token followed by arguments */
print_stmt: TOKEN_PRINT args { $$ = stmt_create(STMT_PRINT,0,0,$2,0,0,0,0); printf(">==t19===============>print statement\n"); }
          ;

/* A postfix is an identifier followed by a postfix add or subtract token */
postfix: identifier TOKEN_POSTFIX_ADD { $$ = expr_create(EXPR_INCREMENT,expr_create_name($1),0); printf(">==t17===============>postfix increment\n"); }
      | identifier TOKEN_POSTFIX_MINUS { $$ = expr_create(EXPR_DECREMENT,expr_create_name($1),0); printf(">==t14===============>postfix decrement\n"); }
      ;

/* An optional assignment is empty or an assignment */
opt_assignment: assignment { $$ = $1; printf(">==t10===============>opt_assignment: assignment\n"); }
              | /* epsilon */ { $$ = 0; printf(">==t11===============>opt_assignment epsilon \n"); }
              ;

/* An optional expression is empty or an expression */
opt_expr: expr { $$ = $1; printf(">==t12===============>opt_expr: expr\n"); }
        | /* epsilon */ { $$ = 0; printf(">==t14===============>opt_expr: epsilon\n"); }
        ;

/* An optional increment is empty or a postfix */
opt_increment: assignment { $$ = $1; printf(">==t15===============>opt_increment: assignment\n"); }
            | postfix { $$ = $1; printf(">==t16===============>opt_increment: postfix\n"); }
            | /* epsilon */ { $$ = 0; printf(">==t18===============>opt_increment epsilon\n"); }
            ;

/* A literal is a true, false, int literal, char literal, or string literal token */
literal: TOKEN_TRUE { $$ = expr_create_boolean_literal(1); printf(">==t11===============>Boolean literal (true)\n"); }
      | TOKEN_FALSE { $$ = expr_create_boolean_literal(0); printf(">==t10==============>Boolean literal (false)\n"); }
      | TOKEN_LITERAL_INT { $$ = expr_create_integer_literal(atoi(yytext)); printf(">==t12===============>Integer literal %s\n", yytext); }
      | TOKEN_LITERAL_CHAR { $$ = expr_create_char_literal(yytext[1]); printf(">==t13===============>Character literal %s\n", yytext);  }
      | TOKEN_LITERAL_STRING { $$ = expr_create_string_literal(yytext); printf(">==t14===============>String literal %s\n", yytext);  }
      ;

/* An atomic type is a boolean, integer, char, or string token */
atomic_type: TOKEN_BOOLEAN   { $$ = type_create(TYPE_BOOLEAN,0,0); printf(">==t18===============>Boolean type created\n"); }
          | TOKEN_INTEGER   { $$ = type_create(TYPE_INTEGER,0,0); printf(">==t19===============>Integer type created\n"); }
          | TOKEN_CHAR    { $$ = type_create(TYPE_CHARACTER,0,0); printf(">==t20===============>Character type created\n"); }
          | TOKEN_STRING    { $$ = type_create(TYPE_STRING,0,0); printf(">==t11===============>String type created\n"); }
          ;

/* A return type is an atomic type or void token */
return_type: atomic_type  { $$ = $1; printf(">==tr===============>return_type: atomic_type\n"); }
          | TOKEN_VOID { $$ = type_create(TYPE_VOID,0,0); printf(">==tv===============>return_type: void created\n"); }
          ;

/* A relational operator is an equal, no equal, greater, greater than or equal, less, or less than or equal token */
relational_op: TOKEN_EQUAL  { $$ = EXPR_EQUAL; printf(">==teq===============>relational_op: equal\n"); }
            | TOKEN_NOT_EQUAL { $$ = EXPR_NOT_EQUAL; printf(">==tnq===============>relational_op: not equal\n"); }
            | TOKEN_GREATER { $$ = EXPR_GREATER_THAN; printf(">==tg===============>relational_op: greater\n"); }
            | TOKEN_GREATER_EQUAL { $$ = EXPR_GREATER_EQUAL; printf(">==tge===============>relational_op: greater equal\n"); }
            | TOKEN_LESS { $$ = EXPR_LESS_THAN; printf(">==tl===============>relational_op: less\n"); }
            | TOKEN_LESS_EQUAL { $$ = EXPR_LESS_EQUAL; printf(">==tle===============>relational_op: less equal\n"); }
            ;

/* A logical operator is an and or or token */
logical_op: TOKEN_LOGICAL_AND { $$ = EXPR_AND; printf(">==tand===============>logical_op: and\n"); }
          | TOKEN_LOGICAL_OR {  $$ = EXPR_OR; printf(">==tor===============>logical_op: or\n"); }
          ;
%%

/* Display an error message in the console */
void yyerror(char const *s) {
   fprintf(stderr, "%s\n", s);
}