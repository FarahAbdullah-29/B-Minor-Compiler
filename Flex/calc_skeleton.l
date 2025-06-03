/* recognize tokens for a calculator and print them out */

%{
  enum yytokentype {
    NUMBER = 258,
    ADD = 259,
    EOL = 998,
    EXIT = 999
  };

  int yylval;
%}

%option noyywrap

%%

"+" { return ADD; }
exit { return EXIT; }
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
\n  { return EOL; }
[ \t] { /* ignore whitespace - note no returned value,
             yylex() will keep looking for a token */ }
.   { printf("Warning: character %c skipped\n", *yytext); }

%%

int main(int argc, char **argv) {
  int token;

  // Keep looping until EXIT or end of input encountered
  while ((token = yylex()) != EXIT && token != 0) {
    printf("Token Value:%d", token);
    if (token == NUMBER) {
      printf(" = %d\n", yylval);
    } else {
      printf("\n");
    }
  }

  return 0;
}
