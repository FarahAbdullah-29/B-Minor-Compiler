b:boolean;
s:string = "Hello, World";

boolit: function void (val: integer) {
	b = val % 2 == 0;
}
main: function integer () = {
	print s;
	print illegal_var@name; 
	x:integer = 0;
	for (x = 0;x < 25;x++) {
		if (x % 3 == 0) {
			print x;
		} else {
			boolit(x);
		}
	}
	print b;
}
