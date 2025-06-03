#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for a phone number */
struct phone_num {
	char *country_code;
	char *number;
	int tollfree;
};

/* A small program to demonstrate malloc() and free() */
int main() {
	// Declare some pointers for different data types
	int *a;
	char *b;
	double *c;
	struct phone_num *d;
	
	// Allocate storage for single values
	a = (int *) malloc(sizeof(int));
	b = (char *) malloc(sizeof(char));
	c = (double *) malloc(sizeof(double));
	d = (struct phone_num *) malloc(sizeof(struct phone_num));

	// Initialize the values
	*a = 25;
	*b = 'M';
	*c = 123.456;
	d->country_code = "1";
	d->number = "5185800001";
	d->tollfree = 0;

	// Show some of the values
	printf("%d %c %g\n", *a, *b, *c);
	printf("(%s) %s (%stoll free)\n", 
		d->country_code, d->number, d->tollfree? "" : "not ");

	// Free the storage
	free(a);
	free(b);
	free(c);
	free(d);

	// Allocate storage for arrays
	a = (int *) malloc(sizeof(int) * 5);
	b = (char *) malloc(sizeof(char) * 15);
	c = (double *) malloc(sizeof(double) * 3);
	d = (struct phone_num *) malloc(sizeof(struct phone_num) * 2);

	// Initialize the data in the arrays
	for (int i = 0;i < 5;++i) 
		a[i] = i * 5;

	strcpy(b, "Hello, World");

	for (int i = 0;i < 3;++i) 
		*(c + i) = 3.14159 * (i * i);

	d->country_code = "1";
	d->number = "8008008000";
	d->tollfree = 1;
	(d + 1)->country_code = "44";
	(d + 1)->number = "02012345678";
	(d + 1)->tollfree = 0;

	// Show some of the values in the arrays
	printf("%d %s %g\n", *(a + 3), b, c[2]);

	for (int i = 0;i < 2;++i)
		printf("(%s) %s (%stoll free)\n", 
			d[i].country_code, d[i].number,
			d[i].tollfree? "" : "not ");


	// Free the storage
	free(a);
	free(b);
	free(c);
	free(d);
}
