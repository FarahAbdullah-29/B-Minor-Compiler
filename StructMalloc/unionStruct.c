#include <stdio.h>

/* A structure representing a plug-in device */
struct plug_in {
	float wattage;
	char* prong_style;
};

/* A structure representing a battery-powered device */
struct battery {
	char* battery_style;
	int runtime;
};

/* A union made up of the two structures */
union device {
	struct plug_in plug;
	struct battery portable;
};

/* Create variables of the union type, populate one of the
  members and demonstrate reading from the correct and
	incorrect members. */
int main() {
	union device desk_lamp;
	desk_lamp.plug.wattage = 75;
	desk_lamp.plug.prong_style = "Spaded 2-prong";

	union device flashlight;
	flashlight.portable.battery_style = "2 D Cells";
	flashlight.portable.runtime = 10;

	printf("Desk lamp wattage? %f\n", desk_lamp.plug.wattage);
	printf("Flashlight batteries? %s\n", flashlight.portable.battery_style);

	// Oops...
	printf("\n");
	printf("Desk lamp runtime? %d\n", desk_lamp.portable.runtime);
	printf("Flashlight wattage? %f\n", flashlight.plug.wattage);
}
