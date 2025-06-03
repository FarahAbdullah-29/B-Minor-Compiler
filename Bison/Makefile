%.c: %.y
%.c: %.l

simple_calc:	simple_calc.l simple_calc.y
	bison -d simple_calc.y
	flex simple_calc.l
	cc -o $@ simple_calc.tab.c lex.yy.c

ast_calc:	ast_calc.l ast_calc.y ast_calc.h ast_calc.c
	bison -d ast_calc.y
	flex ast_calc.l
	cc -o $@ ast_calc.tab.c lex.yy.c ast_calc.c

clean:
	rm -f a.out *.o lex.yy.c *.tab.c ast_calc simple_calc *.tab.h
