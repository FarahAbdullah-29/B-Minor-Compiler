# Makefile for the semantic analysis lab

PROGRAM=semantics

OBJS=b-minor-parser-ast.o b-minor-scanner.o ast_printer.o main.o static_semantic_tests.o hash_table.o type_check.o

PRIOR_OBJS=ast_library.o scope.o symbol.o

SRCS=b-minor-scanner.c b-minor-parser-ast.c ast_printer.c main.c static_semantic_tests.c hash_table.c type_check.c

CC=cc

all:$(PROGRAM)

ast_printer.o: ast_printer.c ast_printer.h
	$(CC) -c -o $@ ast_printer.c

static_semantic_tests.o: static_semantic_tests.c static_semantic_tests.h
	$(CC) -c -o $@ static_semantic_tests.c

hash_table.o: hash_table.c hash_table.h
	$(CC) -c -o $@ hash_table.c

main.o: main.c tokens.h ast_library.h ast_printer.h scope.h symbol.h type_check.h static_semantic_tests.h
	$(CC) -c -o $@ main.c

type_check.o: type_check.c type_check.h
	$(CC) -c -o $@ type_check.c

semantics:$(OBJS) $(PRIOR_OBJS)
	$(CC) $(OBJS) $(PRIOR_OBJS) -o $@ -lm

clean:;	rm -f $(OBJS) core ∗~ *.output *.tab.? semantics
