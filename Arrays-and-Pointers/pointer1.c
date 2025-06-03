#include <stdio.h>

/* Basic pointer examples */

int main() {
	int x = 1, y = 2, z[6];
	int *ip;

	for (int i = 0;i < 6;++i)
		z[i] = 0;

	// Display the initial values	
	printf("After initialization:\n");
	printf("x=%d\ty=%d\t*ip=%d\tip=%p\n", x, y, *ip, ip);
	for (int i = 0;i < 6;++i)
		printf("z[%d]=%d\t", i, z[i]);
	printf("\n");

	// Manipulate the values using pointers
	ip = &x;
	y = *ip;
	*ip = 0;
	ip = &z[4];
	*ip = 25;

	// Display the resulting values
	printf("\nAfter manipulation\n");
	printf("x=%d\ty=%d\t*ip=%d\tip=%p\n", x, y, *ip, ip);
	for (int i = 0;i < 6;++i)
		printf("z[%d]=%d\t", i, z[i]);
	printf("\n");
}
