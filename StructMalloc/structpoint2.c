#include <stdio.h>

/* A structure representing a 2D point */
struct point {
	int x;
	int y;
};

/* A structure representing a 2D rectangle, specifically
	using the upper left and lower right points to
	define it */
struct rect {
	struct point ul;
	struct point lr;
};

/* Function declarations */
struct point makepoint(int x, int y);
struct rect makerect(struct point *ul, struct point *lr);
int ptinrect(struct point *p, struct rect *r);

/* Create some points and a rectangle. 
	Report some information about them */
int main() {
	struct point origin, *op = &origin;
	struct point middle, *mp = &middle;
	struct point end, *ep = &end;
	struct point pointless, *pp = &pointless;
	struct rect screen, *sp = &screen;

	origin = makepoint(0, 0);
	middle = makepoint(5, 5);
	end = makepoint(10, 10);
	pointless = makepoint(20, 15);
	screen = makerect(op, ep);

	printf("origin (%d,%d)  middle (%d,%d)  end (%d,%d)\n",
		op->x, op->y, mp->x, mp->y, ep->x, ep->y);

	printf("Is middle in the screen? %d\n", ptinrect(mp, sp));
	printf("Is pointless in the screen? %d\n", ptinrect(pp, sp));
}

/* Create a 2D point from x and y components */
struct point makepoint(int x, int y) {
	struct point temp;

	temp.x = x;
	temp.y = y;

	return temp;
}

/* Create a 2D rectangle from upper left and lower right components */
struct rect makerect(struct point *ul, struct point *lr) {
	struct rect temp;

	temp.ul = *ul;
	temp.lr = *lr;

	return temp;
}

/* Return 1 if p is within the bounds of r, 0 if not */
int ptinrect(struct point *p, struct rect *r) {
	return p->x >= r->ul.x && p->x < r->lr.x 
		&& p->y >= r->ul.y && p->y < r->lr.y;
}

