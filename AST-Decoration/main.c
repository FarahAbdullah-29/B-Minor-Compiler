#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#include "tokens.h"
#include "ast_library.h"
#include "ast_printer.h"
#include "static_semantic_tests.h"
#include "scope.h"
#include "symbol.h"
#include "type_check.h"

extern int yylex();
extern char *yytext;

extern struct decl *parser_result;

void print_ast(char *description, struct decl *ast_root) {
	printf("\n************AST Output************\n");
	printf("***%s***\n", description);
	decl_print(ast_root);
}

int parse() {
	// Set this to 1 to see the stack data, 0 to suppress it
	yydebug = 0;
	if (yyparse() == 0) {
		printf("Parse successful\n");

		// Output a text-representation of the AST
		print_ast("After Parse", parser_result);

		// *** Semantic analysis ***
		// Uncomment as you build out the resolver and the type checks
		printf("\nType Checking Begins...\n");
		scope_enter();	// initialize scope
		printf("\n Resolver\n");
		decl_resolve(parser_result);
		if (typecheck_error_count()) {
		 	printf("!!AST decorating checks failed\n");
			return 1;
		} else {
            // Print the AST with symbols added (decorated)
    		print_ast("After Decorating", parser_result);
			printf(">>AST decorating checks passed\n");
		}
	} else {
		printf("Parse failed.\n");
		return 1;
	}

	return 0;
}

int main() {
    int ret_val = 0;

	// See static_semantic_tests.c and static_semantic_tests.h for testing code
#if TEST_SCOPE_SYMBOLS
	test_scopes_symbols();
#endif

#if TEST_SCOPES
	test_scopes();
#endif

#if !TEST_SCOPES && !TEST_SCOPE_SYMBOLS
	ret_val = parse();
#endif

    return ret_val;
}
