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