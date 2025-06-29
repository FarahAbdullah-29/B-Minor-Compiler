#include <stdio.h>



/**
Question 1: The symbol \a produces an alert, \b is a backspace, \\ is a backslash
**/
/* print Fahrenheit-Celsius table
   for Fahrenheit temps 0, 20, ..., 300 */
int main() {
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
