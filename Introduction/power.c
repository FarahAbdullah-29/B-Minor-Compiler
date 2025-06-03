#include <stdio.h>

/* declare the power function */
int power(int m, int n);

/* test the power function */
int main() {
	int i;
	for (i = 0;i < 10;++i)
		printf("%d %d %d\n", i, power(2, i), power(3, i));
}

/* power: raise base to n-th power; n >= 0 */

int power(int base, int n){
    if(n == 0){
        return 1;
    }else{
        return base * power(base, n-1);
    }
}