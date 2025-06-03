
%{
/* Recognize tokens for the calculator.
   Bison will create the tokens

   Need to add the regex and action for each
   token and for numeric (reals) literals */

#include "ast_calc.h"
#include "ast_calc.tab.h"
%}

%option noyywrap nodefault yylineno

EXP   ([Ee][-+]?[0-9]+)

%%

"-"?[0-9]+"."[0-9]*{EXP}? |
"-"?"."?[0-9]+{EXP}?    { yylval.d = atof(yytext); return TOKEN_NUMBER; }
"+" {return TOKEN_ADD;}
"-" {return TOKEN_SUB;}
"*" {return TOKEN_MULT;}
"*" {return TOKEN_MULT;}
"/" {return TOKEN_DIV;}
"|" {return TOKEN_ABS;}
"(" {return TOKEN_OPAREN;}
")" {return TOKEN_CPAREN;}

\n      { return TOKEN_EOL;}

"//".* { /* ignore single line comment */ }
[ \t] { /* ignore whitespace */ }
exit  { return TOKEN_EXIT; }
.     { yyerror("Unexpected character %c\n", *yytext); }

%%
