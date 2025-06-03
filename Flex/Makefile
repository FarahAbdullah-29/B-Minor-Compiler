# Example Makefile for building the hello program 
# from main and hello source files

PROGRAM=hello-world
OBJS=hello.o main.o
SRCS=hello.c main.c hello.h main.h
CC=cc

# Default target, build entire project
all:$(PROGRAM)

hello.o: hello.c hello.h
	$(CC) -c -o $@ hello.c

main.o: main.c main.h hello.h
	$(CC) -c -o $@ main.c
  
$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) -o $@ -lm

# Clean up all generated files
clean:; rm -f $(OBJS) hello-world a.out lex.yy.c

# Mark all source files as updated
touchsrc:; touch $(SRCS)

# Force rebuild of entire project
rebuild: touchsrc all
	

