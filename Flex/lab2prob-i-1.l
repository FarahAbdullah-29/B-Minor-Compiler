%option noyywrap

%%
[Ll][Oo][Ll] {printf("Laughing out loud");}
[Aa][Bb][Tt] {printf("About");}
[Aa][Ff][Kk] {printf("Away from Keyboard");}
[Aa][Kk][Aa] {printf("Also known as");}
[Bb][Ff][4][Ll] {printf("Best friends forever");}
[Bb][Tt][Ww] {printf("By the way");}
[Cc][Yy][Aa] {printf("See ya");}
[Ff][Ww][Dd] {printf("Forward");}
[Ff][Yy][Ii] {printf("For your information");}
[Gg][Gg] {printf("Good game");}
%%

int main(int argc, char **argv) {
  yylex();
  return 0;
}