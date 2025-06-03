// Test functions for the scoping and type comparison operations

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#include "static_semantic_tests.h"
#include "symbol.h"
#include "scope.h"
#include "type_check.h"

// As the scoping and type managing code is written, modify the macro
// values in the .h file to enable this code to run

// See the main function (in main.c) for calls to test functions

#define PASS_FAIL(bool) (bool? "<PASS>" : "<!FAIL!>")

#if TEST_SCOPES
void test_scopes() {
	printf("Should be no scopes yet. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 0));
	scope_enter();
	printf("Should be one scope. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 1));
	scope_enter();
	printf("Should be two scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 2));
	scope_enter();
	printf("Should be three scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 3));
	scope_exit();
	printf("Should be two scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 2));
	scope_enter();
	printf("Should be three scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 3));
	scope_exit();
	printf("Should be two scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 2));
	scope_exit();
	printf("Should be one scope. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 1));
	scope_exit();
	printf("Should be zero scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 0));
	scope_enter();
	printf("Should be one scope. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 1));
	scope_exit();
	printf("Should be zero scopes. Num scopes: %d %s\n", scope_level(), PASS_FAIL(scope_level() == 0));
	scope_exit();
	printf("SHOULD NOT SEE THIS MESSAGE - error should have occurred");
}
#endif

#if TEST_SCOPE_SYMBOLS
void test_scopes_symbols() {
	scope_enter();

	struct type *t = type_create(TYPE_INTEGER, 0, 0);
	struct symbol *a = symbol_create(SYMBOL_GLOBAL, t, "a");
	scope_bind("a", a);

	printf("Should find a in any scope: %s\n", PASS_FAIL(scope_lookup("a")));
	printf("Should find a in current scope: %s\n", PASS_FAIL(scope_lookup_current("a")));

	scope_enter();

	t = type_create(TYPE_INTEGER, 0, 0);
	struct symbol *b = symbol_create(SYMBOL_LOCAL, t, "b");
	scope_bind("b", b);

	printf("Should find a in any scope: %s\n", PASS_FAIL(scope_lookup("a")));
	printf("Should NOT find a in current scope: %s\n", PASS_FAIL(scope_lookup_current("a")==NULL));
	printf("Should find b in any scope: %s\n", PASS_FAIL(scope_lookup("b")));
	printf("Should find b in current scope: %s\n", PASS_FAIL(scope_lookup_current("b")));

	scope_exit();

	printf("Should find a in any scope: %s\n", PASS_FAIL(scope_lookup("a")));
	printf("Should find a in current scope: %s\n", PASS_FAIL(scope_lookup_current("a")));
	printf("Should NOT find b in any scope: %s\n", PASS_FAIL(scope_lookup("b") == NULL));
	printf("Should NOT find b in current scope: %s\n", PASS_FAIL(scope_lookup_current("b") == NULL));
}
#endif
