#include <stdio.h>
#include "main.h"
#include "hello.h"

/* Begins program execution and calls the hello() function, 
   passing command line arguments */
int main(int argc, char **argv) {
	printf("Default Message: %s\n", DEFAULT_MESSAGE);
	printf("Hello message: %s\n", HELLO_MESSAGE);
	hello(argc, argv);
	return RET_VALUE;
}

