extern inline void cordic_assembly(int *x, int *y, int *z, int mode) {
	
	int* val;
	int x_temp;

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

	if (mode == 0) {
		val = &z_local;
	} else {
		val = &y_local;
	}

	x_local = x_local << 16;
	y_local = y_local << 16;
	z_local = z_local << 16;

	for (int i = 0; i < 14; i++) {
		x_temp = x_local;
		if ((*val < 0 && mode == 0) || (*val >= 0 && mode != 0)) {
			x_local = x_local + (y_local >> i);
			y_local = y_local - (x_temp >> i);
			z_local = z_local + local_elem_angle[i];
		} else {
			x_local = x_local - (y_local >> i);
			y_local = y_local + (x_temp >> i);
			z_local = z_local - local_elem_angle[i];
		}
	}
	*x = x_local;
	*y = y_local;
	*z = z_local;
}