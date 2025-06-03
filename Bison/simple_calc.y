%{
/* Basic parser-based calculator

   These concepts are fundamental
   to building your parser

   You are expected to understand this code

   I've typed the chapter 5 code for you to allow
   you to explore and work with it,
   NOT so you can ignore chapter 5
*/

  #include <stdio.h>
  int yylex();

  int yyerror(char *s) {
    fprintf(stderr, "error: %s\n", s);
    return 0;
  }
%}

/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token EOL

%%

calclist: /* epsilon, erasure rule */
        | calclist abs EOL { printf("= %d\n", $2); }
        ;

abs: exp { $$ = $1; /* default action, could leave action out */ }
  | ABS exp { $$ = $2 >= 0? $2 : - $2; }
  ;

exp: factor   { $$ = $1; /* default action, could leave action out */ }
  | exp ADD factor {$$ = $1 + $3; }
  | exp SUB factor {$$ = $1 - $3; }
  ;

factor: term  { $$ = $1; /* default action, could leave action out */ }
  | factor MUL term { $$ = $1 * $3; }
  | factor DIV term { $$ = $1 / $3; }
  ;

term: NUMBER  { $$ = $1; /* default action, could leave action out */ }
  ;

%%

int main(int argc, char **argv) {
  yyparse();
  return 0;
}
