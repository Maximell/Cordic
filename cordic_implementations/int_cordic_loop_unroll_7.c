extern inline void int_cordic_loop_unroll_7(int* restrict x, int* restrict y, int* restrict z, const int* restrict lookup) {

	int x_next, y_next, z_next;
	int x_local, y_local, z_local;
	int i, j, k, l, m, n, o;
	x_local = *x;
	y_local = *y;
	z_local = *z;

	i = 0;
	j = 1;
	k = 2;
	l = 3;
	m = 4;
	n = 5;
	o = 6;

	for(; i < PRECISION; i+=7, j+=7, k+=7, l+=7, m+=7, n+=7, o+=7) {

		// 1
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

		// 2
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

		// 3
		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> k);
			y_next = y_local - (x_local >> k);
			z_next = z_local + lookup[k];
		} else {
			x_next = x_local - (y_local >> k);
			y_next = y_local + (x_local >> k);
			z_next = z_local - lookup[k];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;

		// 4
		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> l);
			y_next = y_local - (x_local >> l);
			z_next = z_local + lookup[l];
		} else {
			x_next = x_local - (y_local >> l);
			y_next = y_local + (x_local >> l);
			z_next = z_local - lookup[l];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;

		// 5
		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> m);
			y_next = y_local - (x_local >> m);
			z_next = z_local + lookup[m];
		} else {
			x_next = x_local - (y_local >> m);
			y_next = y_local + (x_local >> m);
			z_next = z_local - lookup[m];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;

		// 6
		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> n);
			y_next = y_local - (x_local >> n);
			z_next = z_local + lookup[n];
		} else {
			x_next = x_local - (y_local >> n);
			y_next = y_local + (x_local >> n);
			z_next = z_local - lookup[n];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;

		// 7
		if (z_local & 0x80000000) {
			x_next = x_local + (y_local >> o);
			y_next = y_local - (x_local >> o);
			z_next = z_local + lookup[o];
		} else {
			x_next = x_local - (y_local >> o);
			y_next = y_local + (x_local >> o);
			z_next = z_local - lookup[o];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;
	} 

	*x = x_local;
	*y = y_local;
}