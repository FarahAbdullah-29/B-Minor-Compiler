#include <stdio.h>
#include <string.h>

/* Try out a few of the string library functions */

int main() {
	char *a = "parser";
	char *b = "parsley";
	char c[20];

	strcpy(c, a);
	printf("a:%s len:%d\n", a, strlen(a));
	printf("b:%s len:%d\n", b, strlen(b));
	printf("c:%s len:%d\n", c, strlen(c));
	printf("strcmp %s vs. %s: %d\n", a, b, strcmp(a, b));
	printf("strcmp %s vs. %s: %d\n", a, c, strcmp(a, c));
}
	
