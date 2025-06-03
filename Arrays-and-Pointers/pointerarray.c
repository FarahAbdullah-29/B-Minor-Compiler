#include <stdio.h>

/* Iterate through a pointer array of character arrays */

int slen(char *s);

int main() {
	char *words[3];
	words[0] = "banana";
	words[1] = "cherry";
	words[2] = "apple";

	// print out the arrays
	for (int i = 0;i < 3;++i) {
		char *letter = words[i];
		printf("length %d\t", slen(words[i]));
		while (*letter) 
			printf("[%c]", *letter++);
		printf(" \n");
	}
}

/* calculate the length of the string, not counting the null terminator.
    This is provided to see how we can use pointer arithmetic to
    traverse an array. The function strlen() should be used to
    obtain the length of a string. */
int slen(char *s) {
	char* e = s;
	while (*e++)
		;
	return e - s;
}
