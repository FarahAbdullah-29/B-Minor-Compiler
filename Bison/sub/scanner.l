%{
#include <stdio.h>
#include "tokens.h"
%}


%%

\+ { return TOKEN_PLUS; }
\- { return TOKEN_MINUS; }
\* { return TOKEN_MUL; }
\/ {return TOKEN_DIV; }
\( { return TOKEN_LPAREN; }
\) { return TOKEN_RPAREN; }
; { return TOKEN_SEMI; }
[0-9]+ { return TOKEN_INT; }
[ \t\n] { }
. { printf("error %d\n", *yytext); }

%%
