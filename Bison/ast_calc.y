%{
/* Grammar for calculator using an AST

    Need to add union, tokens, types,
    and the grammar rules and actions.

    A few grammar rules and actions are
    given as a starting point
*/

#include <stdio.h>
#include <stdlib.h>
#include "ast_calc.h"
int yylex();
%}

%union {
  struct ast *a;
  double d;
}

/* declare tokens and types */
%token <d> TOKEN_NUMBER
%token TOKEN_EOL
%token TOKEN_EXIT
%token TOKEN_ADD
%token TOKEN_SUB
%token TOKEN_MULT
%token TOKEN_DIV
%token TOKEN_ABS
%token TOKEN_OPAREN
%token TOKEN_CPAREN

%type <a> abs exp factor term


%%

calclist: /* nothing (epsilon/erasure) */
        | calclist abs TOKEN_EOL {
                    printf("= %4.4g\n", eval($2));
                    treefree($2);
                    printf("> ");
          }
        | calclist TOKEN_EOL { printf("> "); } // blank line or a comment
        | calclist TOKEN_EXIT TOKEN_EOL { printf("Goodbye\n"); return 0; }
        ;

abs: exp {$$ = $1;}
  | TOKEN_ABS exp {$$ = newast(TOKEN_ABS, $2, NULL);}
  ;
exp: factor
  | exp TOKEN_ADD factor { $$ = newast(TOKEN_ADD, $1, $3); }
  | exp TOKEN_SUB factor { $$ = newast(TOKEN_SUB, $1, $3); }
  ;
factor: term
  | factor TOKEN_MULT term {$$ = newast(TOKEN_MULT, $1, $3);}
  | factor TOKEN_DIV term {$$ = newast(TOKEN_DIV, $1, $3); }
      ;
term: TOKEN_NUMBER{$$ = newnum($1);}
  |TOKEN_OPAREN exp TOKEN_CPAREN {$$ = $2;}
  ;

%%
