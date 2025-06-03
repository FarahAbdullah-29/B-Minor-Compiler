#include <stdio.h>
#include <string.h>

/* simple character array copy version 2 */

#define THE_MESSAGE "To be or not to be"

int scpy(char *s, char *t);

int main() {
	char cpy[strlen(THE_MESSAGE) + 1];
	*cpy = '\0';
	printf("cpy=%s\n", cpy);
	scpy(cpy, THE_MESSAGE);
	printf("cpy=%s\n", cpy);
}

/* scpy: copy values in array t to array s */
int scpy(char *s, char *t) {
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}
