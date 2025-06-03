// Test function prototypes for the scoping and type comparison operations

#ifndef STATIC_SEMANTIC_TESTS_H

#define STATIC_SEMANTIC_TESTS_H

// See main function (in main.c) for calls to test functions

// As the scoping and type managing code is written, set these macros
// to non-zero values to enable the testing code to run
#define TEST_SCOPES 0
#define TEST_SCOPE_SYMBOLS 0

#if TEST_SCOPES
void test_scopes();
#endif

#if TEST_SCOPE_SYMBOLS
void test_scopes_symbols();
#endif

#endif // STATIC_SEMANTIC_TESTS_H
