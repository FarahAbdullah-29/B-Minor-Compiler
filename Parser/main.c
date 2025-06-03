#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#include "tokens.h"
#include "ast_library.h"
#include "ast_printer.h"

/* The lexical analyzer's lexing function to
    obtain the next token */
extern int yylex();

/* The current lexeme */
extern char *yytext;

/* The root of the AST */
extern struct decl *parser_result;

/* Only perform lexical analysis, no parse */
int just_lex() {
	while (1) {
		int t = yylex();
		if (t == 0) {
			break;
		}
		if (t == TOKEN_ERROR) {
			printf("ERROR. Unrecognized token: %s\n", yytext);
		} else {
			printf("token: %d  text: %s\n", t, yytext);
		}
	}
	return 0;
}

/* Perform a parse and evaluate the result */
int parse() {
	// Set this to 1 to see the stack data, 0 to suppress it
	yydebug = 0;

    // Perform the parse and check
    // for success or failure
	if (yyparse() == 0) {
		printf("Parse successful\n");
		// Print the resulting AST
		decl_print(parser_result);
	} else {
		printf("Parse failed.\n");
		return 1;
	}

	return 0;
}

/* Run the parser */
int main() {
	return parse();
}
