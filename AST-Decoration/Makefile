# Makefile for the semantic analysis lab

PROGRAM=semantics

OBJS=b-minor-parser-ast.o b-minor-scanner.o ast_library.o ast_printer.o main.o static_semantic_tests.o hash_table.o scope.o symbol.o type_check.o

SRCS=b-minor-scanner.c b-minor-parser-ast.c ast_library.c ast_printer.c main.c static_semantic_tests.c hash_table.c scope.c symbol.c type_check.c

CC=cc

all:$(PROGRAM)

ast_library.o: ast_library.c ast_library.h
	$(CC) -c -o $@ ast_library.c

ast_printer.o: ast_printer.c ast_printer.h
	$(CC) -c -o $@ ast_printer.c

static_semantic_tests.o: static_semantic_tests.c static_semantic_tests.h symbol.h scope.h type_check.h
	$(CC) -c -o $@ static_semantic_tests.c

hash_table.o: hash_table.c hash_table.h
	$(CC) -c -o $@ hash_table.c

main.o: main.c tokens.h ast_library.h ast_printer.h scope.h symbol.h type_check.h static_semantic_tests.h
	$(CC) -c -o $@ main.c

scope.o: scope.c scope.h hash_table.h ast_library.h
	$(CC) -c -o $@ scope.c

symbol.o: symbol.c symbol.h ast_library.h
	$(CC) -c -o $@ symbol.c

type_check.o: type_check.c type_check.h ast_library.h symbol.h scope.h ast_printer.h
	$(CC) -c -o $@ type_check.c

semantics:$(OBJS)
	$(CC) $(OBJS) -o $@ -lm

clean:;	rm -f $(OBJS) core ∗~ *.output *.tab.? semantics
