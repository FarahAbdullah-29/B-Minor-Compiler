#include <stdio.h>

/* Use the optional code preprocessor feature */

//#define SET1 1
#define SET2 0

int main() {
	int x, y;

#ifdef SET1
	x = 1;
#else
	x = 2;
#endif

#if SET2
	y = 1;
#elif SET1
	y = 2;
#else
	y = 3;
#endif

	printf("x=%d\ty=%d\n", x, y);
}
