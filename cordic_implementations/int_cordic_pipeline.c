extern inline void int_cordic_pipeline(int* restrict x, int* restrict y, int* restrict z, const int* restrict lookup) {
	
	int x_next, y_next, z_next;
	int lookup_value;
	int x_local, y_local, z_local;

	x_local = *x;
	y_local = *y;
	z_local = *z;


	lookup_value = lookup[0];
	for (int i=0; i < PRECISION; i++) {
	
		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> i);
			y_next = y_local - (x_local >> i);
			z_next = z_local + lookup_value;
		} else {
			x_next = x_local - (y_local >> i);
			y_next = y_local + (x_local >> i);
			z_next = z_local - lookup_value;
		}
		i++;
		lookup_value = lookup[i];
		x_local = x_next; y_local = y_next; z_local = z_next;
	}

	*x = x_local;
	*y = y_local;
}
