%{
  #include "tokens.h"
%}

%option noyywrap

%%
array { return TOKEN_ARRAY; }
boolean { return TOKEN_BOOLEAN; }
char { return TOKEN_CHAR; }
else { return TOKEN_ELSE; }
false { return TOKEN_FALSE; }
for { return TOKEN_FOR; }
function { return TOKEN_FUNCTION; }
if { return TOKEN_IF; }
integer { return TOKEN_INTEGER; }
print { return TOKEN_PRINT; }
return { return TOKEN_RETURN; }
string { return TOKEN_STRING; }
true { return TOKEN_TRUE; }
void { return TOKEN_VOID; }
while { return TOKEN_WHILE; }
[0-9]+ { return TOKEN_LITERAL_INT; }
\'(.|\\.)\' { return TOKEN_LITERAL_CHAR; }
"\""(\\.|[^""\\])*\""" { return TOKEN_LITERAL_STRING; }
([A-Za-z]|_)([A-Za-z]|_|[0-9])* { return TOKEN_IDENT; }
\+\+ { return TOKEN_POSTFIX_ADD; }
\-\- { return TOKEN_POSTFIX_MINUS; }
\>= { return TOKEN_GREATER_EQUAL; }
\<= { return TOKEN_LESS_EQUAL; }
\=\= { return TOKEN_EQUAL; }
\!\= { return TOKEN_NOT_EQUAL; }
\&\& { return TOKEN_LOGICAL_AND; }
\|\| { return TOKEN_LOGICAL_OR; }
\! { return TOKEN_NOT; }
\( { return TOKEN_LPAREN; }
\) { return TOKEN_RPAREN; }
\[ { return TOKEN_LBRACKET; }
\] { return TOKEN_RBRACKET; }
\{ { return TOKEN_LBRACE; }
\} { return TOKEN_RBRACE; }
\^ { return TOKEN_EXPONENTIAL; }
\* { return TOKEN_MUL; }
\/ { return TOKEN_DIV; }
\% { return TOKEN_MOD; }
\+ { return TOKEN_PLUS; }
\- { return TOKEN_MINUS; }
\, { return TOKEN_COMMA; }
\> { return TOKEN_GREATER; }
\< { return TOKEN_LESS; }
\= { return TOKEN_ASSIGN; }
\: { return TOKEN_COLON; }
; { return TOKEN_SEMI; }
. { return TOKEN_ERROR; }
[ \t\n]	{ };
%%