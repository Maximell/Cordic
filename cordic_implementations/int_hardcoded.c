extern inline void int_hardcoded(int* restrict x, int* restrict y, int* restrict z, const int* restrict lookup) {

	int x_next, y_next, z_next;

	int x_local, y_local, z_local;
	x_local = *x;
	y_local = *y;
	z_local = *z;

	// & 0X80000000 tests if z_local is +'ve or -'ve
	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 0);
		y_next = y_local - (x_local >> 0);
		z_next = z_local + 0x6487;
	} else {
		x_next = x_local - (y_local >> 0);
		y_next = y_local + (x_local >> 0);
		z_next = z_local - 0x6487;
	}
	
	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 1);
		y_next = y_local - (x_local >> 1);
		z_next = z_local + 0x3B58;
	} else {
		x_next = x_local - (y_local >> 1);
		y_next = y_local + (x_local >> 1);
		z_next = z_local - 0x3B58;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 2);
		y_next = y_local - (x_local >> 2);
		z_next = z_local + 0x1F5A;
	} else {
		x_next = x_local - (y_local >> 2);
		y_next = y_local + (x_local >> 2);
		z_next = z_local - 0x1F5A;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 3);
		y_next = y_local - (x_local >> 3);
		z_next = z_local + 0xFEA;
	} else {
		x_next = x_local - (y_local >> 3);
		y_next = y_local + (x_local >> 3);
		z_next = z_local - 0xFEA;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 4);
		y_next = y_local - (x_local >> 4);
		z_next = z_local + 0x7FC;
	} else {
		x_next = x_local - (y_local >> 4);
		y_next = y_local + (x_local >> 4);
		z_next = z_local - 0x7FC;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 5);
		y_next = y_local - (x_local >> 5);
		z_next = z_local + 0x3FF;
	} else {
		x_next = x_local - (y_local >> 5);
		y_next = y_local + (x_local >> 5);
		z_next = z_local - 0x3FF;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 6);
		y_next = y_local - (x_local >> 6);
		z_next = z_local + 0x1FF;
	} else {
		x_next = x_local - (y_local >> 6);
		y_next = y_local + (x_local >> 6);
		z_next = z_local - 0x1FF;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 7);
		y_next = y_local - (x_local >> 7);
		z_next = z_local + 0xFF;
	} else {
		x_next = x_local - (y_local >> 7);
		y_next = y_local + (x_local >> 7);
		z_next = z_local - 0xFF;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 8);
		y_next = y_local - (x_local >> 8);
		z_next = z_local + 0x7F;
	} else {
		x_next = x_local - (y_local >> 8);
		y_next = y_local + (x_local >> 8);
		z_next = z_local - 0x7F;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 9);
		y_next = y_local - (x_local >> 9);
		z_next = z_local + 0x3F;
	} else {
		x_next = x_local - (y_local >> 9);
		y_next = y_local + (x_local >> 9);
		z_next = z_local - 0x3F;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 10);
		y_next = y_local - (x_local >> 10);
		z_next = z_local + 0x1F;
	} else {
		x_next = x_local - (y_local >> 10);
		y_next = y_local + (x_local >> 10);
		z_next = z_local - 0x1F;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 11);
		y_next = y_local - (x_local >> 11);
		z_next = z_local + 0xF;
	} else {
		x_next = x_local - (y_local >> 11);
		y_next = y_local + (x_local >> 11);
		z_next = z_local - 0xF;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 12);
		y_next = y_local - (x_local >> 12);
		z_next = z_local + 0x7;
	} else {
		x_next = x_local - (y_local >> 12);
		y_next = y_local + (x_local >> 12);
		z_next = z_local - 0x7;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 13);
		y_next = y_local - (x_local >> 13);
		z_next = z_local + 0x3;
	} else {
		x_next = x_local - (y_local >> 13);
		y_next = y_local + (x_local >> 13);
		z_next = z_local - 0x3;
	}

	x_local = x_next; y_local = y_next; z_local = z_next;

	if (z_local & 0x80000000) {
		x_next = x_local + (y_local >> 14);
		y_next = y_local - (x_local >> 14);
		z_next = z_local + 0x1;
	} else {
		x_next = x_local - (y_local >> 14);
		y_next = y_local + (x_local >> 14);
		z_next = z_local - 0x1;
	}

	*x = x_next;
	*y = y_next;

}