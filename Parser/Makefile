YFLAGS=-v --defines=tokens.h

YACC=bison

PROGRAM=parser

OBJS=b-minor-parser-ast.o b-minor-scanner.o ast_library.o ast_printer.o

PARSER_OBJS=$(OBJS) main.o

TEST_OBJS=$(OBJS) ast_library_tests.o

CC=cc

all:$(PROGRAM)

ast_library.o: ast_library.c ast_library.h
	$(CC) -c -o $@ ast_library.c

ast_printer.o: ast_printer.c ast_printer.h
	$(CC) -c -o $@ ast_printer.c

b-minor-parser-ast.c:b-minor-parser.y
	bison $(YFLAGS) --output=$@ b-minor-parser.y

parser:$(PARSER_OBJS)
	$(CC) $(PARSER_OBJS) -o $@ -lm

ast_library_tests: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $@ -lm

clean:;	rm -f $(PARSER_OBJS) core ∗~ *.output *.tab.? b-minor-parser-ast.c tokens.h parser ast_library_tests
