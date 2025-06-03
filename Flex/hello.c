#include <stdio.h>
#include "hello.h"

/* Displays information about the command line */
void hello(int argc, char **argv) {
	printf("\nHello function has been called\n");
	
	printf("The command you used is %s\n", *argv);
	
	if (argc > 1) {
		printf("\nAdditional arguments were provided, here they are:\n");
		int i;
		for (i = 1;i < argc;i++) {
			printf("Argument %d: %s\n", i, argv[i]);
		}
	}
}
