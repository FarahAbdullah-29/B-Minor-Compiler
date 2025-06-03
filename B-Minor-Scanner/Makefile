YFLAGS=-v --defines=tokens.h

YACC=bison

PROGRAM=a.out

OBJS=b-minor-scanner.o test-scanner.o utils.o

SRCS=test-scanner.c utils.c b-minor-scanner.l

CC=cc

all:$(PROGRAM)

b-minor-scanner.c: b-minor-scanner.l
	flex -o $@ b-minor-scanner.l

a.out:$(OBJS)
	$(CC) $(OBJS) -o $@ -lm

clean:;	rm -f $(OBJS) core ∗~ a.out b-minor-scanner.c
