// Header file for longestline2 example

#ifndef LONGESTLINE2H

#define LONGESTLINE2H

#define MAXLINE 1000	/* maximum input line length */

extern char line[MAXLINE];	// current input line
extern int max;		// maximum length seen so far
extern char longest[MAXLINE];	// longest line found so far

int getnextline(void);
void copy(void);

#endif // LONGESTLINE2H
