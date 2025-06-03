These concepts are fundamental
to building your parser

You are expected to understand this code

I've typed the chapter 5 code for you to allow
you to explore and work with it,
NOT so you can ignore chapter 5

--------------------------------------

Each of the steps is broken out into a separate
Bison configuration file and main function.
1. Validator
2. Interpreter
3. Hand-made AST
4. Parser-generated AST

A Makefile is setup to allow building each
example directly:
make validator
make interpreter
make astmanual
make astparser

The specific commands for running the steps
manually are listed below.

There is a valid test expression in the file
expression-valid.txt

There is an expression containing a syntax error
in the file expression-error.txt

Note that the lexical analyzer, defined in scanner.l,
isn't impacted by the changes to the parser.

We rebuild the lexical analyzer for each example since
Bison is generating the tokens.h file and we shouldn't
assume the constants will be the same.

==============================================
>>>Step 1: Validator example (pages 70-72)

>>Files Used:
Bison Grammar File: p71-grammar.y
Flex Lexical Analyzer (Scanner) File: scanner.l
Test Main Function: p72-testmain.c

>>To Build:
bison -v --defines=tokens.h --output=validator.c p71-grammar.y
flex scanner.l
cc -o validator lex.yy.c p72-testmain.c validator.c

>>To Test:
./validator
Type in an expression and press enter
Press [CTRL]-D

>>Alternate test approach:
(Redirect the test expression into the program)
./validator < expression-valid.txt
./validator < expression-error.txt

==============================================
>>>Step 2: Interpreter calculator example (pages 74-75)

>>Files Used:
Bison Grammar File: p75-grammar.y
Flex Lexical Analyzer (Scanner) File: scanner.l
Test Main Function: p75-testmain.c

>>To Build:
bison -v --defines=tokens.h --output=interpreter.c p75-grammar.y
flex scanner.l
cc -o interpreter lex.yy.c interpreter.c p75-testmain.c

>>To Test:
./interpreter
Type in an expression and press enter
Then press [CTRL]-D

>>Alternate test approach:
(Redirect the test expression into the program)
./interpreter < expression-valid.txt
./interpreter < expression-error.txt

==============================================
>>>Step 3: Hand-made AST calculator example (pages 75-77)
(Note: we used the AST expression code on pages 80-81 as well)

>>Files Used:
Bison Grammar File: N/A
Flex Lexical Analyzer (Scanner) File: N/A
AST-related structures and functions: expr.h and expr.c
Test Main Function: p77-testmain.c

>>To Build:
cc -o astmanual p77-testmain.c expr.c

>>To Test:
./astmanual

==============================================
>>> Step 4: Complete Parser-generated AST calculator (pages 78-81)

>>Files Used:
Bison Grammar File: p78-grammar.y
Flex Lexical Analyzer (Scanner) File: scanner.l
Test Main Function: p78-testmain.c

>>To Build:
bison -v --defines=tokens.h --output=astparser.c p78-grammar.y
flex scanner.l
cc -o astparser lex.yy.c astparser.c expr.c p78-testmain.c

>>To Test:
./astparser
Type in an expression and press enter
Then press [CTRL]-D

>>Alternate test approach:
(Redirect the test expression into the program)
./astparser < expression-valid.txt
./astparser < expression-error.txt
