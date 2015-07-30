extern inline void cordic_assembly_rotational(int *x, int *y, int *z, int* [] elem_angle) {
	
	int* val;
	int x_temp;

	val = z;

	*x = *x << 16;
	*y = *y << 16;
	*z = *z << 16;

	for (int i = 0; i < 14; i++) {
		x_temp = *x;
		if (val < 0) {
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
