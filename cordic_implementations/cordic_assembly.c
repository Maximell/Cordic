extern inline void cordic_assembly(int *x, int *y, int *z, const int elem_angle[14]) {
	
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
