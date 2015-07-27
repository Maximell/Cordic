extern inline void int_cordic_simp_flow(int *x, int *y, int *z, const int *lookup) {
	
	int temp;

	for (int i=0; i < PRECISION; i++) {
	
		if (*z & 0x80000000) {
			temp = *x + (*y >> i);
			*y = *y - (*x >> i);
			*x = temp;
			*z = *z + lookup[i];
		} else {
			temp = *x - (*y >> i);
			*y = *y + (*x >> i);
			*x = temp;
			*z = *z - lookup[i];
		}
	}
}
