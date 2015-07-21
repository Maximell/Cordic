extern inline void int_cordic(int *x, int *y, int *z, const int *lookup) {
	
	int sign, temp;

	for (int i=0; i < PRECISION; i++) {
		
		if (*z >= 0) {
			sign = 1;
		} else {
			sign = 0;
		}
	
		if (sign) {
			temp = *x - (*y >> i);
			*y = *y + (*x >> i);
			*x = temp;
			*z = *z - lookup[i];
		} else {
			temp = *x + (*y >> i);
			*y = *y - (*x >> i);
			*x = temp;
			*z = *z + lookup[i];
		}
	}
}
