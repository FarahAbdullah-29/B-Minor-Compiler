/* Count words, lines, and characters in a file */

%{
  int chars = 0;
  int words = 0;
  int lines = 0;
%}

%option noyywrap

%%

[a-zA-Z]+   { words++; chars += strlen(yytext); }
\n          { chars++; lines++; }
.           { chars++; }

%%

int main(int argc, char **argv) {
  yylex();
  printf("%8d %8d %8d\n", lines, words, chars);
  return 0;
}
