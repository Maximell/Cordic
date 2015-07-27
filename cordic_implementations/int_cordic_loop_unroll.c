extern inline void int_cordic_loop_unroll(int* restrict x, int* restrict y, int* restrict z, const int* restrict lookup) {

	int x_next, y_next, z_next;
	int x_local, y_local, z_local;
	int i, j;
	x_local = *x;
	y_local = *y;
	z_local = *z;

	i = 0;
	j = 1;

	for(; i < PRECISION; i+=2, j+=2) {

		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> i);
			y_next = y_local - (x_local >> i);
			z_next = z_local + lookup[i];
		} else {
			x_next = x_local - (y_local >> i);
			y_next = y_local + (x_local >> i);
			z_next = z_local - lookup[i];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;

		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> j);
			y_next = y_local - (x_local >> j);
			z_next = z_local + lookup[j];
		} else {
			x_next = x_local - (y_local >> j);
			y_next = y_local + (x_local >> j);
			z_next = z_local - lookup[j];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;
	} 

	*x = x_local;
	*y = y_local;
}