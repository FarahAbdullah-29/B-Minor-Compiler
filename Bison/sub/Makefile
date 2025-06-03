%.c: %.y
%.c: %.l

validator: scanner.l p71-grammar.y p72-testmain.c
	bison -v --defines=tokens.h --output=validator.c p71-grammar.y
	flex scanner.l
	cc -o $@ lex.yy.c p72-testmain.c validator.c


interpreter: scanner.l p75-grammar.y p75-testmain.c
	bison -v --defines=tokens.h --output=interpreter.c p75-grammar.y
	flex scanner.l
	cc -o $@ lex.yy.c interpreter.c p75-testmain.c

astmanual: p77-testmain.c expr.c
	cc -o $@ p77-testmain.c expr.c

astparser: scanner.l p78-grammar.y	p78-testmain.c expr.c
	bison -v --defines=tokens.h --output=astparser.c p78-grammar.y
	flex scanner.l
	cc -o $@ lex.yy.c astparser.c expr.c p78-testmain.c

clean:
	rm -f validator validator.c interpreter interpreter.c astmanual astparser astparser.c *.o lex.yy.c *.output tokens.h
