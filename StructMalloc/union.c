#include <stdio.h>

/* Declares a union with two members, an int and a float.
  Declares a variable of the union type and sets one
	member to a value. Prints the two members to demonstrate
	the fact that they share memory, e.g. corrupted values
	are seen for the member not most recently set. */
int main() {
	/* Declares a union with two members, and int and a float */
	union number {
		int i;
		float f;
	};

	/* Declare a variable of the union type */
	union number num;

	/* Assign a value to the int member and print the two
	  members, demonstrating the float member is not useful */
	num.i = 15;
	printf("%10d\t%10.5f\n", num.i, num.f);

	/* Assign a value to the float member and print the two
	  members, demonstrating the int member is not useful */
	num.f = 15;
	printf("%10d\t%10.5f\n", num.i, num.f);
}
