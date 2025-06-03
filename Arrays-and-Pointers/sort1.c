#include <stdio.h>

/* Simple sorter version 1 */

void swap(int a, int b);

int main() {
	int vals[] = { 3, 2, 1 };
	for (int i = 0;i < 2;i++) 
		for (int j = 0;j < 2;j++) 
			if (vals[j] > vals[j + 1]) 
				swap(vals[j], vals[j + 1]);
	for (int i = 0;i < 3;++i)
		printf("%d\t", vals[i]);
	printf("\n");
}

/* Swap two ints - well, try to */
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
