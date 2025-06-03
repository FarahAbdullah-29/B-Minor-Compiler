%{
/* Basic calculator scanner.

   These concepts are fundamental
   to building your parser

   You are expected to understand this code

   I've typed the chapter 5 code for you to allow
   you to explore and work with it,
   NOT so you can ignore chapter 5
*/

  // Bison creates the token constants
  // based on .y file tokens
  #include "simple_calc.tab.h"
%}

%option noyywrap

%%

"+" { return ADD; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"|" { return ABS; }
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
\n  { return EOL; }
[ \t] { /* ignore whitespace - note no returned value, yylex() will keep looking for a token */ }
.   { printf("Undefined character %c skipped\n", *yytext); }

%%
