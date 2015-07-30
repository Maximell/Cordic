extern inline double fixed_to_float(int fixed) {
	return fixed / FLOAT_SHIFT;
}

extern inline int float_to_fixed(double float_number) {
	return (int)(float_number * BASE_SHIFT);
}

extern inline int sign_decision(cordic_mode mode, int val) {

	int result;

	if (val < 0) {
		result = 1;
	} else {
		result = 0;
	}

	if (mode == ROTATIONAL) {
		return result;
	} else {
		return !result;
	}
}

extern inline void cordic(int* x, int* y, int* z, cordic_mode mode) {
	
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

extern inline void cordic_optimized(int* restrict x, int* restrict y, int* restrict z, cordic_mode mode) {

	int *val;

	const int local_elem_angle[] = {
		2949120,
		1740967,
		919789,
		466945,

		234379,
		117304,
		58666,
		29335,
		
		14668,
		7334,
		3667,
		1833,
		
		917,
		458	
	};

	int x_local = *x;
	int y_local = *y;
	int z_local = *z;

	if (mode == ROTATIONAL) {
		val = &z_local;
	} else {
		val = &y_local;
	}

	x_local = x_local << SHIFT;
	y_local = y_local << SHIFT;
	z_local = z_local << SHIFT;

	int x_next, y_next, z_next;

	int i=0;
	int j=1;

	for (; i < PRECISION; i+=2, j+=2) {
		
		if ((*val < 0 && mode == ROTATIONAL) || (*val >= 0 && mode != ROTATIONAL)) {
			x_next = x_local + (y_local >> i);
			y_next = y_local - (x_local >> i);
			z_next = z_local + local_elem_angle[i];
		} else {
			x_next = x_local - (y_local >> i);
			y_next = y_local + (x_local >> i);
			z_next = z_local - local_elem_angle[i];
		}

		x_local = x_next; y_local = y_next; z_local = z_next;

		if ((*val < 0 && mode == ROTATIONAL) || (*val >= 0 && mode != ROTATIONAL)) {
			x_next = x_local + (y_local >> j);
			y_next = y_local - (x_local >> j);
			z_next = z_local + local_elem_angle[j];
		} else {
			x_next = x_local - (y_local >> j);
			y_next = y_local + (x_local >> j);
			z_next = z_local - local_elem_angle[j];
		}
		x_local = x_next; y_local = y_next; z_local = z_next;

	}
	*x = x_local;
	*y = y_local;
	*z = z_local;
}

extern inline double cos_cordic(int angle) {

	int x = 1;
	int y = 0;
	int z = angle;

	cordic(&x,&y,&z,ROTATIONAL);

	return fixed_to_float((double)x) / SCALE_CONSTANT;
}

extern inline double sin_cordic(int angle) {

	int x = 1;
	int y = 0;
	int z = angle;

	cordic(&x,&y,&z,ROTATIONAL);

	return fixed_to_float((double)y) / SCALE_CONSTANT;
}