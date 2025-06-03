/* recognize tokens for a calculator and print them out */

%{
  #include "add_sub.h"
  #include <math.h>

  enum yytokentype {
    NUMBER = 258,
    SUB = 260;
    ADD = 259,
    EOL = 998,
    EXIT = 999
  };

  int yylval;
%}

%option noyywrap

%%

"+" { return ADD; }
"-" { return SUB; }
exit { return EXIT; }
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
\n  { return EOL; }
[ \t] { /* ignore whitespace - note no returned value,
             yylex() will keep looking for a token */ }
.   { printf("Warning: character %c skipped\n", *yytext); }

%%

int main(int argc, char **argv) {
  int token;
  int currentValue = 0;
  int latestOperator = -1;

  // Keep looping until EXIT or end of input encountered
  while ((token = yylex()) != EXIT && token != 0) {
    printf("Token Id:%d\n", token);
    switch (token) {
      case NUMBER:
        if (latestOperator > 0) {
          switch (latestOperator) {
            case ADD:
              currentValue = add(currentValue, yylval);
              break;
            case SUB:
              currentValue = subtract(currentValue, yylval);
            }
        } else if (latestOperator == -1) {
          // start of expression
          currentValue = yylval;
        } else {
          printf("ERROR: Unexpected literal: %d\n", yylval);
        }

        latestOperator = 0;
        break;
      case ADD:
      case SUB;
        if (latestOperator) {
          printf("ERROR: unexpected operator: %c\n", *yytext);
        }
        latestOperator = token;
        break;
      case EOL:
        printf("Calculated value = %d\n", currentValue);
        // reset values for new expression starting on next line
        latestOperator = -1;
        currentValue = 0;
        break;
      default:
        printf("ERROR: Unhandled token value: %d\n", token);
    }
  }

  // If exit typed at the end of an expression, the result
  // won't have been printed in the loop
  if (latestOperator >= 0) {
    printf("Calculated value: %d\n", currentValue);
  }

  return 0;
}
