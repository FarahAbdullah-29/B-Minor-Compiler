#include <stdio.h>

#define MAXLINE 1000	/* maximum input line length */

int getnextline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest line */
int main() {
	int len;	// current line length
	int max;	// maximum length seen so far
	char line[MAXLINE];	// current input line
	char longest[MAXLINE];	// longest line found so far

	max = 0;
	while ((len = getnextline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) // there was a line
		printf("%s\n", longest);

	return 0;
}

/* getnextline: read a line into s, return length of line */
int getnextline(char *s, int lim) {
	int c, i;
	char *cp = s;

	for (i = 0;i < lim - 1 && (c = getchar()) != EOF && c != '\n';++i)
		*cp++ = c;
	if (c == '\n') {
		*cp++ = c;
		++i;
	}
	*cp = '\0';
	return i;
}

/* copy: copy 'from' into 'to': assume it is big enough */
void copy(char *to, char *from) {
	int i;
	i = 0;
	while (*to++ = *from++ != '\0')
		++i;
}

