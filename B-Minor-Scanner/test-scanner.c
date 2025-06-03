#include "stdio.h"
#include "utils.h"

int yylex(void);
int main(int argc, char **argv) {
    int token;
    while(token = yylex()){
        printf("%d", token);
        char* token_name = get_token_name(token);
        printf("[%s]\n", token_name);
    }
    return 0;   
}
