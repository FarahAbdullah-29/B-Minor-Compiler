#include <stdio.h>

#define max(A, B) ((A) > (B) ? (A) : (B))
#define square(x) x * x
#define dprint(e) printf(#e " = %g\n", e)

int main() {
	int x;
	int a = 2;
	int b = 3;

	x = max(a, b);
	printf("%d\n", x);

	x = max(a++, b++);
	printf("%d %d %d\n", x, a, b);

	x = square(a + 1);
	printf("%d %d\n", a + 1, x);

	dprint(5.0 / 2.0);
}
