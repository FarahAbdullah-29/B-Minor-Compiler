#include <stdio.h>
#include "longestline2.h"

/* print longest line */
int main() {
	int len;	// current line length

	max = 0;
	while ((len = getnextline()) > 0)
		if (len > max) {
			max = len;
			copy();
		}
	if (max > 0) // there was a line
		printf("%s\n", longest);

	return 0;
}

/* getnextline: specialized version using external array */
int getnextline(void) {
	int c, i;

	for (i = 0;i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n';++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: specialized version using external array */
void copy() {
	int i;

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
