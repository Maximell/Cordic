extern inline void cordic_assembly(int *x, int *y, int *z, cordic_mode mode) {
	
	int* val;
	int x_temp;

	if (mode == ROTATIONAL) {
		val = z;
	} else {
		val = y;
	}

	*x = *x << SHIFT;
	*y = *y << SHIFT;
	*z = *z << SHIFT;

	for (int i = 0; i < PRECISION; i++) {
		x_temp = *x;
		if (sign_decision(mode, *val)) {
			*x = *x + (*y >> i);
			*y = *y - (x_temp >> i);
			*z = *z + elem_angle[i];
		} else {
			*x = *x - (*y >> i);
			*y = *y + (x_temp >> i);
			*z = *z - elem_angle[i];
		}
	}
}
